#include "simulation.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

Simulation::Simulation(int maxSteps, int refresh, const vector<vector<Cell>> &initialRegion) : maxTimeSteps(maxSteps), refreshRate(refresh), region(initialRegion), availableWorkers(0), availableGoods(0)
{
}

void Simulation::simulateRegion()
{
    cout << "\n======================\n";
    cout << "Initial Region Layout:\n";
    cout << "======================\n";
    printRegion();

    for (int step = 1; step <= maxTimeSteps; ++step)
    {
        cout << "\n=== Time Step " << step << " ===\n";
        cout << "Available workers: " << availableWorkers << "\n";
        cout << "Available goods: " << availableGoods << "\n";

        bool changed = applyGrowthStep();

        if (step % refreshRate == 0)
            printRegion();

        if (!changed)
        {
            cout << "No change detected. Halting simulation.\n";
            break;
        }
    }

    // Output summary stats
    cout << "\nFinal region state:\n";
    printRegion();

    int rPop = 0, iPop = 0, cPop = 0, totalPoll = 0;

    for (const auto &row : region)
    {
        for (const auto &cell : row)
        {
            if (cell.type == 'R')
                rPop += cell.population;
            if (cell.type == 'I')
                iPop += cell.population;
            if (cell.type == 'C')
                cPop += cell.population;
            totalPoll += cell.pollution;
        }
    }

    cout << CYAN;
    cout << "\n======================\n";
    cout << "Population Statistics:\n";
    cout << "======================\n";
    cout << RESET;

    cout << BOLD << "Residential population: " << rPop << '\n';
    cout << BOLD << "Industrial population: " << iPop << '\n';
    cout << BOLD << "Commercial population: " << cPop << '\n';
    cout << RESET;

    cout << CYAN;
    cout << "\n======================\n";
    cout << "Final pollution state:\n";
    cout << "======================\n";
    cout << RESET;
    for (const auto &row : region)
    {
        for (const auto &cell : row)
        {
            // cout << cell.pollution;
            cout << setw(3) << min(cell.pollution, 9); // ensures single-digit display
        }
        cout << '\n';
    }
    cout << "\n"
         << BOLD << "Total pollution: " << totalPoll << "\n\n";
    cout << RESET;

    analyzeRegion(); // Ask user for area after showing stats
}

void Simulation::printRegion() const
{
    for (const auto &row : region)
    {
        for (const auto &cell : row)
        {
            string display;

            if (cell.type == 'R')
            {
                display = cell.population > 0 ? to_string(cell.population) : "R";
                cout << GREEN << setw(3) << display << RESET << ' ';
            }
            else if (cell.type == 'C')
            {
                display = cell.population > 0 ? to_string(cell.population) : "C";
                cout << CYAN << setw(3) << display << RESET << ' ';
            }
            else if (cell.type == 'I')
            {
                display = cell.population > 0 ? to_string(cell.population) : "I";
                cout << YELLOW << setw(3) << display << RESET << ' ';
            }
            else if (cell.type == 'T')
            {
                cout << BLUE << setw(3) << "T" << RESET << ' ';
            }
            else if (cell.type == '#')
            {
                cout << BLUE << BOLD << setw(3) << "#" << RESET << ' ';
            }
            else if (cell.type == '-')
            {
                cout << WHITE << setw(3) << "-" << RESET << ' ';
            }
            else if (cell.type == 'P')
            {
                cout << RED << BOLD << setw(3) << "P" << RESET << ' ';
            }
            else
            {
                cout << setw(3) << " " << ' ';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

bool Simulation::applyGrowthStep()
{
    vector<vector<Cell>> next = region;
    bool changed = false;
    availableWorkers = 0;
    availableGoods = 0;

    // Count total workers before growth
    for (const auto &row : region)
        for (const auto &cell : row)
            if (cell.type == 'R')
                availableWorkers += cell.population;

    // INDUSTRIAL growth
    for (size_t y = 0; y < region.size(); ++y)
    {
        for (size_t x = 0; x < region[0].size(); ++x)
        {
            Cell &cell = region[y][x];
            if (cell.type != 'I' || cell.population >= 2 || availableWorkers < 2)
                continue;

            int pop = cell.population;
            int adjPop = 0;
            bool hasPower = false;

            for (int dy = -1; dy <= 1; ++dy)
            {
                for (int dx = -1; dx <= 1; ++dx)
                {
                    int ny = y + dy, nx = x + dx;
                    if (ny < 0 || ny >= region.size() || nx < 0 || nx >= region[0].size())
                        continue;
                    if (dy == 0 && dx == 0)
                        continue;
                    const Cell &adj = region[ny][nx];
                    if (adj.type == 'T' || adj.type == '#')
                        hasPower = true;
                    if (adj.population >= pop)
                        adjPop++;
                }
            }

            bool grow = false;
            if ((pop == 0 && (hasPower || adjPop >= 1)) || (pop == 1 && adjPop >= 2))
            {
                grow = true;
            }

            if (grow)
            {
                next[y][x].population++;
                availableWorkers -= 2;
                availableGoods += next[y][x].population; // Produces goods
                changed = true;
            }
        }
    }

    // COMMERCIAL growth
    for (size_t y = 0; y < region.size(); ++y)
    {
        for (size_t x = 0; x < region[0].size(); ++x)
        {
            Cell &cell = region[y][x];
            if (cell.type != 'C' || cell.population >= 1 || availableWorkers < 1 || availableGoods < 1)
                continue;

            int pop = cell.population;
            int adjPop = 0;
            bool hasPower = false;

            for (int dy = -1; dy <= 1; ++dy)
            {
                for (int dx = -1; dx <= 1; ++dx)
                {
                    int ny = y + dy, nx = x + dx;
                    if (ny < 0 || ny >= region.size() || nx < 0 || nx >= region[0].size())
                        continue;
                    if (dy == 0 && dx == 0)
                        continue;
                    const Cell &adj = region[ny][nx];
                    if (adj.type == 'T' || adj.type == '#')
                        hasPower = true;
                    if (adj.population >= pop)
                        adjPop++;
                }
            }

            bool grow = false;
            if ((pop == 0 && (hasPower || adjPop >= 1)))
            {
                grow = true;
            }

            if (grow)
            {
                next[y][x].population++;
                availableWorkers--;
                availableGoods--;
                changed = true;
            }
        }
    }

    // RESIDENTIAL growth
    for (size_t y = 0; y < region.size(); ++y)
    {
        for (size_t x = 0; x < region[0].size(); ++x)
        {
            Cell &cell = region[y][x];
            if (cell.type != 'R' || cell.population >= 5)
                continue;

            int pop = cell.population;
            int adjPop = 0;
            bool hasPower = false;

            for (int dy = -1; dy <= 1; ++dy)
            {
                for (int dx = -1; dx <= 1; ++dx)
                {
                    int ny = y + dy, nx = x + dx;
                    if (ny < 0 || ny >= region.size() || nx < 0 || nx >= region[0].size())
                        continue;
                    if (dy == 0 && dx == 0)
                        continue;
                    const Cell &adj = region[ny][nx];
                    if (adj.type == 'T' || adj.type == '#')
                        hasPower = true;
                    if (adj.population >= pop)
                        adjPop++;
                }
            }

            bool grow = false;
            if ((pop == 0 && (hasPower || adjPop >= 1)) ||
                (pop == 1 && adjPop >= 2) || (pop == 2 && adjPop >= 4) ||
                (pop == 3 && adjPop >= 6) || (pop == 4 && adjPop >= 8))
            {
                grow = true;
            }

            if (grow)
            {
                next[y][x].population++;
                changed = true;
            }
        }
    }

    region = next;
    spreadPollution();
    return changed;
}

void Simulation::spreadPollution()
{
    for (size_t y = 0; y < region.size(); ++y)
    {
        for (size_t x = 0; x < region[0].size(); ++x)
        {
            if (region[y][x].type == 'I')
            {
                int basePoll = region[y][x].population;
                for (int dy = -1; dy <= 1; ++dy)
                {
                    for (int dx = -1; dx <= 1; ++dx)
                    {
                        int ny = y + dy, nx = x + dx;
                        if (ny < 0 || ny >= region.size() || nx < 0 || nx >= region[0].size())
                            continue;
                        if (dy == 0 && dx == 0)
                            continue;
                        region[ny][nx].pollution += std::max(0, basePoll - 1);
                    }
                }
            }
        }
    }
}

bool Simulation::areEqual(const std::vector<std::vector<Cell>> &a, const std::vector<std::vector<Cell>> &b)
{
    for (size_t y = 0; y < a.size(); ++y)
        for (size_t x = 0; x < a[0].size(); ++x)
            if (a[y][x].population != b[y][x].population)
                return false;
    return true;
}

void Simulation::analyzeRegion() const
{
    int y1, x1, y2, x2;
    cout << "Enter the coordinates of the area to analyze (startRow startCol endRow endCol): \n";
    cin >> y1 >> x1 >> y2 >> x2;

    // Bounds checking
    while (y1 < 0 || y2 >= region.size() || x1 < 0 || x2 >= region[0].size() || y1 > y2 || x1 > x2)
    {
        cout << "Invalid coordinates. Try again: ";
        cin >> y1 >> x1 >> y2 >> x2;
    }

    int rPop = 0, iPop = 0, cPop = 0, totalPoll = 0;

    for (int y = y1; y <= y2; ++y)
    {
        for (int x = x1; x <= x2; ++x)
        {
            const Cell &cell = region[y][x];
            if (cell.type == 'R')
                rPop += cell.population;
            if (cell.type == 'I')
                iPop += cell.population;
            if (cell.type == 'C')
                cPop += cell.population;
            totalPoll += cell.pollution;
        }
    }

    cout << CYAN;
    cout << "\n==============\n";
    cout << "Area Analysis:\n";
    cout << "==============\n";
    cout << RESET;
    cout << BOLD << "Residential Population: " << rPop << '\n';
    cout << BOLD << "Industrial Population: " << iPop << '\n';
    cout << BOLD << "Commercial Population: " << cPop << '\n';
    cout << BOLD << "Total Pollution: " << totalPoll << "\n\n";
}
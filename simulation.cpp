#include "simulation.h"

void Simulation::printRegion(const vector<vector<char>> &region)
{
    for (const auto &row : region)
    {
        for (char c : row)
            cout << setw(3) << c << ' ';
        cout << '\n';
    }
}

void Simulation::simulateRegion(const vector<vector<char>> &region)
{
    for (int step = 1; step <= maxTimeSteps; ++step)
    {
        cout << "\n=== Time Step " << step << " ===\n";
        cout << "Available workers: 1\n";
        cout << "Available goods: 0\n";
        cout << "Current Region State: \n";

        printRegion(region);
    }
}

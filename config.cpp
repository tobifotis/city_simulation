#include "config.h"

string LoadConfig::getRegionLayout() const
{
    // Attempt to open file => [config1.txt]
    ifstream file(m_configFile);

    if (!file) // If the file does not exist
    {
        cout << "\nError: Unable to open " << m_configFile << endl;
        cout << "Ensure you typed in 'config1.txt' correctly.\n\n";
        return "";
    }

    string line;
    while (getline(file, line))
    {
        if (line.find("Region") == 0) // If the line starts with "Region"
        {
            // Extract substring starting at index 14 to the end of the string
            return line.substr(14);
        }
    }

    return "";
}

LoadConfig::LoadConfig(const string &file) : m_configFile(file)
{
    getGrid();
}

// This function will read and display content of 'config1.txt'
void LoadConfig::displayConfiguration() const
{
    // Attempt to open file => [config1.txt]
    ifstream file(m_configFile);

    if (!file) // If the file does not exist
    {
        cout << "\nError: Unable to open " << m_configFile << endl;
        cout << "Ensure you typed in 'config1.txt' correctly.\n\n";
        return;
    }

    // Read and display the file => [config1.txt]
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    // Don.t forget to close the file
    file.close();
}

// This function will store a vector of our csv file
void LoadConfig::getGrid()
{
    // Get the csv filename
    string regionFile = getRegionLayout();

    // Attempt to open file => [region1.csv]
    ifstream file(regionFile);

    if (!file) // If the file does not exist
    {
        cout << "\nError: Unable to open " << regionFile << endl;
        return;
    }

    grid.clear();
    string line;

    while (getline(file, line))
    {
        vector<char> row;
        stringstream cellStream(line);
        string cell;

        while (getline(cellStream, cell, ','))
        {
            // Handle empty cells
            if (cell.empty() || cell == " ")
            {
                // Empty cells will just store space
                row.push_back(' ');
            }
            else
            {
                // Store first character of each value
                row.push_back(cell[0]);
            }
        }
        grid.push_back(row);
    }

    file.close();
}

void LoadConfig::displayGrid() const
{
    cout << endl;
    for (const auto &row : grid)
    {
        for (const auto &c : row)
        {
            cout << setw(3) << c << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

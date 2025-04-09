#include "config.h"


bool LoadConfig::readConfig(const string &m_configFileName)
{
    // Attempt to open file => [config1.txt]
    ifstream file(m_configFileName);

    if (!file) // If the file does not exist
    {
        cout << "\nError: Unable to open " << m_configFileName << endl;
        cout << "Ensure you typed in 'config1.txt' correctly.\n\n";
        return false;
    }

    string line;

    while (getline(file, line))
    {
        if (line.find("Region") == 0) // If the line starts with "Region"
        {
            // Extract substring starting at index 14 to the end of the string
            m_regionFileName = line.substr(14);
        }
        else if (line.find("Time") == 0) // If the line starts with "Time"
        {
            // Extract substring starting at index 11 to the end of the string
            m_maxTimeSteps = stoi(line.substr(11));
        }
        if (line.find("Refresh") == 0) // If the line starts with "Refresh"
        {
            // Extract substring starting at index 13 to the end of the string
            m_refreshRate = stoi(line.substr(13));
        }
    }

    file.close();
    return true;
}


bool LoadConfig::readRegionLayout(const string &m_regionFileName)
{
    // Attempt to open file => [region1.csv]
    ifstream file(m_regionFileName);

    if (!file) // If the file does not exist
    {
        cout << "\nError: Unable to open " << m_regionFileName << endl;
        return false;
    }

    regionLayout.clear();
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
        regionLayout.push_back(row);
    }

    file.close();
    return true;
}

// void LoadConfig::displayGrid() const
// {
//     cout << endl;
//     for (const auto &row : grid)
//     {
//         for (const auto &c : row)
//         {
//             cout << setw(3) << c << ' ';
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

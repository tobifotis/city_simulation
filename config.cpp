#include "config.h"

// Should return region1.csv
string LoadConfig::getRegionFileName(const string &configFileName)
{
    // Attempt to open file => [config1.txt]
    ifstream file(configFileName);

    if (!file) // If the file does not exist
    {
        cout << "\nError: Unable to open " << configFileName << endl;
        cout << "Ensure you typed in 'config1.txt' correctly.\n\n";
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

    file.close();
    return "";
}

// Should return 20
int LoadConfig::getMaxTimeSteps(const string &configFileName)
{
    // Attempt to open file => [config1.txt]
    ifstream file(configFileName);

    if (!file) // If the file does not exist
    {
        cout << "\nError: Unable to open " << configFileName << endl;
        cout << "Ensure you typed in 'config1.txt' correctly.\n\n";
    }

    string line;

    while (getline(file, line))
    {
        if (line.find("Time") == 0) // If the line starts with "Time"
        {
            // Extract substring starting at index 11 to the end of the string
            return stoi(line.substr(11));
        }
    }

    file.close();
    return 0;
}

// Should return 1
int LoadConfig::getRefreshRate(const string &configFileName)
{
    // Attempt to open file => [config1.txt]
    ifstream file(configFileName);

    if (!file) // If the file does not exist
    {
        cout << "\nError: Unable to open " << configFileName << endl;
        cout << "Ensure you typed in 'config1.txt' correctly.\n\n";
    }

    string line;

    while (getline(file, line))
    {
        if (line.find("Refresh") == 0) // If the line starts with "Refresh"
        {
            // Extract substring starting at index 13 to the end of the string
            return stoi(line.substr(13));
        }
    }

    file.close();
    return 1;
}

// Reads the config file [config1.txt] to find the region file name [region1.csv],
// then loads and converts that file into a 2D grid of Cell structs.
vector<vector<Cell>> LoadConfig::getRegionLayout(const string &configFileName)
{
    ifstream configFile(configFileName); // Open the main config file.
    string line;
    string regionFileName;

    while (getline(configFile, line))
    {
        if (line.find("Region") == 0) // Look for the line starting with "Region"
        {
            regionFileName = line.substr(14); // Extract the region file name after index 14
            break;
        }
    }

    ifstream file(regionFileName); // Open the region layout file [region1.csv]

    if (!file) // Handle file open failure
    {
        cout << "\nError: Unable to open " << regionFileName << endl;
        return {};
    }

    vector<vector<Cell>> region; // The 2D grid to store Cell structs

    while (getline(file, line)) // Read each row of the region file
    {
        stringstream ss(line); // Split the line by commas
        string cell;
        vector<Cell> row;

        while (getline(ss, cell, ',')) // Process each cell in the row
        {
            char type;
            if (cell.empty() || cell == " ")
            {
                type = ' ';
            }
            else
            {
                type = cell[0];
            }
            row.emplace_back(type); // Default population and pollution to 0
        }
        
        region.push_back(row);
    }

    file.close();
    return region;
}

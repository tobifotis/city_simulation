#include <iostream>
#include <fstream>

#include <vector>
#include <sstream>

#include "region.h"

using namespace std;

void displayInitialRegion()
{
    ifstream File;
    File.open("region1.csv");

    if (!File)
    {
        cout << "Unable to open that file!";
    }

    // This is a vector whose elements will be vector(s)
    vector<vector<string>> initialRegion;

    string line;

    // Read file line by line
    while (getline(File, line))
    {
        // Create a stringstream from the line you get on each iteration
        stringstream sstream(line);

        // Vector for each row
        vector<string> row;

        string cell;

        // Split the line by commas
        // add everything on that line into the row vecotr
        while (getline(sstream, cell, ','))
        {
            row.push_back(cell);
        }

        // push all you get into the data vector
        initialRegion.push_back(row);
    }

    File.close();

    // print 2D Vector
    for (int i = 0; i < initialRegion.size(); i++)
    {
        for (int j = 0; j < initialRegion[i].size(); j++)
        {
            cout << initialRegion[i][j] << "\t";
        }
        cout << "\n\n";
    }
}
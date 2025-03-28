#ifndef LOADCONFIG_H
#define LOADCONFIG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// handle configuration file
class LoadConfig
{
private:
    string m_configFile;
    vector<vector<char>> grid;

    string getRegionLayout() const;

public:
    // Constructor
    LoadConfig(const string &file);

    void displayConfiguration() const;

    void getGrid();

    void displayGrid() const;
};

#endif
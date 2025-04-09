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
public:
    string m_configFileName; // config1.txt

    string m_regionFileName; // region1.csv
    int m_maxTimeSteps;      // 20
    int m_refreshRate;       // 1

    vector<vector<char>> regionLayout; // Grid

    bool readConfig(const string &m_configFileName);
    bool readRegionLayout(const string &m_regionFileName);

    // void displayGrid() const;
};

#endif
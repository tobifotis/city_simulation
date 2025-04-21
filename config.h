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

    string getRegionFileName(const string &m_configFileName);
    int getMaxTimeSteps(const string &m_configFileName);
    int getRefreshRate(const string &m_configFileName);

    vector<vector<char>> regionLayout; // Grid

    vector<vector<char>> getRegionLayout(const string &m_configFileName);
};

#endif
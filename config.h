#ifndef LOADCONFIG_H
#define LOADCONFIG_H

#include "cell.h"

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
    string getRegionFileName(const string &configFileName); // region1.csv
    int getMaxTimeSteps(const string &configFileName);      // 20
    int getRefreshRate(const string &configFileName);       // 1

    // 2d vector of cells
    vector<vector<Cell>> getRegionLayout(const string &configFileName);
};

#endif
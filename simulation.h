#ifndef SIMULATION_H
#define SIMULATION_H

#include "config.h"

class Simulation
{
public:
    LoadConfig config;

    string regionFileName = config.getRegionFileName("config1.txt");
    int maxTimeSteps = config.getMaxTimeSteps("config1.txt");
    int refreshRate = config.getRefreshRate("config1.txt");

    vector<vector<char>> region = config.getRegionLayout("config1.txt");

    void printRegion(const vector<vector<char>> &region);
    void simulateRegion(const vector<vector<char>> &region);
};

#endif

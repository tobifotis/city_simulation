#ifndef SIMULATION_H
#define SIMULATION_H

#include "cell.h"
#include <vector>
#include <iostream>

using namespace std;

class Simulation
{
private:
    int maxTimeSteps;
    int refreshRate;
    vector<vector<Cell>> region;

    int availableWorkers;
    int availableGoods;

public:
    // Constructor
    Simulation(int maxSteps, int refresh, const vector<vector<Cell>> &initialRegion);

    void simulateRegion();
    void printRegion() const;
    bool applyGrowthStep();
    void spreadPollution();
    bool areEqual(const vector<vector<Cell>> &a, const vector<vector<Cell>> &b);
    void analyzeRegion() const;
};

#endif

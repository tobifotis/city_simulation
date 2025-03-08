#include <iostream>
#include <string>

#include "config.h"
#include "region.h"

using namespace std;

int main()
{
    // Variable for file name
    string fileName;

    // Ask the user for file name
    cout << "Hey user, kindly enter the file name: ";
    cin >> fileName;

    string regionLayout = getRegionLayout(fileName);
    int timeLimit = getTimeLimit(fileName);
    int refreshRate = getRefreshRate(fileName);

    cout << "Region Layout: " << regionLayout << endl;
    cout << "Time Limit: " << timeLimit << endl;
    cout << "Refresh Rate: " << refreshRate << "\n\n";

    displayInitialRegion();
}

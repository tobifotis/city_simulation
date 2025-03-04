#include <iostream>
#include "config.h"

#include <fstream>
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

    cout << regionLayout << endl;
    cout << timeLimit << endl;
    cout << refreshRate << endl;
}
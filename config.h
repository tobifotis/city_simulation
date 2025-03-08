#ifndef CONFIG_H
#define CONFIG_H

#include <string>

using namespace std;

string getRegionLayout(const string &fileName);

int getTimeLimit(const string &fileName);

int getRefreshRate(const string &fileName);


#endif
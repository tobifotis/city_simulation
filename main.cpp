#include "config.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void welcomeUser();
void printInitialRegion(const vector<vector<char>> &region);

int main()
{

  welcomeUser();

  string fileName;

  cout << "\nKindly enter file name: ";
  cin >> fileName;

  LoadConfig config;
  string regionFileName = config.getRegionFileName(fileName);
  int maxTimeSteps = config.getMaxTimeSteps(fileName);
  int refreshRate = config.getRefreshRate(fileName);

  vector<vector<char>> region = config.getRegionLayout(fileName);

  cout << "\n"
       << regionFileName << "\n";
  cout << maxTimeSteps << "\n";
  cout << refreshRate << "\n";

  printInitialRegion(region);

  return 0;
}

void welcomeUser()
{
  cout << R"(
    ________       ___      _____ ______           ________      ___      _________     ___    ___ 
   |\   ____\     |\  \    |\   _ \  _   \        |\   ____\    |\  \    |\___   ___\  |\  \  /  /|
   \ \  \___|_    \ \  \   \ \  \\\__\ \  \       \ \  \___|    \ \  \   \|___ \  \_|  \ \  \/  / /
    \ \_____  \    \ \  \   \ \  \\|__| \  \       \ \  \        \ \  \       \ \  \    \ \    / / 
     \|____|\  \    \ \  \   \ \  \    \ \  \       \ \  \____    \ \  \       \ \  \    \/  /  /  
       ____\_\  \    \ \__\   \ \__\    \ \__\       \ \_______\   \ \__\       \ \__\ __/  / /    
      |\_________\    \|__|    \|__|     \|__|        \|_______|    \|__|        \|__||\___/ /     
      \|_________|                                                                    \|___|/      
       )"
       << "\n";

  cout << "\n\t\t\t\t\t***************************\n";
  cout << "\t\t\t\t\t    WELCOME TO SIM CITY  \n";
  cout << "\t\t\t\t\t***************************\n";
}

void printInitialRegion(const vector<vector<char>> &region)
{
  cout << "\n======================\n";
  cout << "Initial Region Layout:\n";
  cout << "======================\n";
  for (const auto &row : region)
  {
    for (char c : row)
      cout << setw(3) << c << ' ';
    cout << '\n';
  }

  cout << endl;
}

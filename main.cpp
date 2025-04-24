#include "config.h"
#include "simulation.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BLUE "\033[34m"

using namespace std;

void welcomeUser();

int main()
{

  welcomeUser();

  string fileName;

  cout << "\nKindly enter file name: ";
  cin >> fileName;

  LoadConfig config;
  string regionFile = config.getRegionFileName(fileName);
  int maxSteps = config.getMaxTimeSteps(fileName);
  int refreshRate = config.getRefreshRate(fileName);

  vector<vector<Cell>> region = config.getRegionLayout(fileName);

  Simulation sim(maxSteps, refreshRate, region);
  sim.simulateRegion();

  return 0;
}

void welcomeUser()
{
  cout << CYAN << R"(
    ________       ___      _____ ______           ________      ___      _________     ___    ___ 
   |\   ____\     |\  \    |\   _ \  _   \        |\   ____\    |\  \    |\___   ___\  |\  \  /  /|
   \ \  \___|_    \ \  \   \ \  \\\__\ \  \       \ \  \___|    \ \  \   \|___ \  \_|  \ \  \/  / /
    \ \_____  \    \ \  \   \ \  \\|__| \  \       \ \  \        \ \  \       \ \  \    \ \    / / 
     \|____|\  \    \ \  \   \ \  \    \ \  \       \ \  \____    \ \  \       \ \  \    \/  /  /  
       ____\_\  \    \ \__\   \ \__\    \ \__\       \ \_______\   \ \__\       \ \__\ __/  / /    
      |\_________\    \|__|    \|__|     \|__|        \|_______|    \|__|        \|__||\___/ /     
      \|_________|                                                                    \|___|/      
       )"
       << RESET << "\n";

  cout << "\n\t\t\t\t============================================\n\n";
  cout << BOLD << BLUE ;
  cout << "\t\t\t\t    W E L C O M E   T O   S I M   C I T Y  \n\n";
  cout << RESET;
  cout << "\t\t\t\t============================================\n";
}

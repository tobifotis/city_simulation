#include "config.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void welcomeUser();

int main()
{

  welcomeUser();

  string fileName;

  cout << "\nKindly enter file name: ";
  cin >> fileName;

  LoadConfig config(fileName);
  config.displayGrid();

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
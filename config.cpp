#include <iostream>
#include <fstream>
#include <unordered_map>
#include "config.h"

using namespace std;

string getRegionLayout(const string &fileName)
{
    unordered_map<string, string> config;

    // Create input file stream
    ifstream file;

    // Attempt to open the file
    file.open(fileName);

    if (file.is_open())
    {
        string key;
        string value;

        // KEY - before delimeter
        getline(file, key, ':');

        // VALUE - after delimeter
        getline(file, value);

        // MAP - key to value
        config[key] = value;
        return config[key]; // print out the value

        file.close();
    }
    else
    {
        cout << "Error opening the file!" << endl;
    }
}

int getTimeLimit(const string &fileName)
{
    unordered_map<string, string> config;

    // Create input file stream
    ifstream file;

    // Attempt to open the file
    file.open(fileName);

    if (file.is_open())
    {
        string key;
        string value;

        // Get KEY and VALUE of the first line
        getline(file, key, ':');
        getline(file, value);

        // Get KEY and VALUE of the second line
        getline(file, key, ':');
        getline(file, value);

        // MAP - key to value
        config[key] = value;
        return stoi(config[key]); // return the integer value

        file.close();
    }
    else
    {
        cout << "Error opening the file!" << endl;
    }
}

int getRefreshRate(const string &fileName)
{
    unordered_map<string, string> config;

    // Create input file stream
    ifstream file;

    // Attempt to open the file
    file.open(fileName);

    if (file.is_open())
    {
        string key;
        string value;

        // Get KEY and VALUE of the first line
        getline(file, key, ':');
        getline(file, value);

        // Get KEY and VALUE of the second line
        getline(file, key, ':');
        getline(file, value);

        // Get KEY and VALUE of the third line
        getline(file, key, ':');
        getline(file, value);

        // MAP - key to value
        config[key] = value;
        return stoi(config[key]); // return the integer value

        file.close();
    }
    else
    {
        cout << "Error opening the file!" << endl;
    }
}
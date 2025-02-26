#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Variable for file name
    string fileName;

    // Ask the user for file name
    cout << "Hey user, kindly enter the file name: ";
    cin >> fileName;

    // Create input file stream
    ifstream file;

    string line;

    // Attempt to open the file
    file.open(fileName);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
    else
    {
        cout << "Error opening the file!" << endl;
    }
}
<div align="center"> 
  <h1>Sim City - A C/C++ City Growth Simulation</h1>
</div>

<br> 

## Introduction
This project simulates the growth of a city over time, focusing on
residential, commercial, and industrial zones, and how pollution
impacts development.

<br> 

## Project Structure
- commercial.cpp/.h    --> Commercial zone logic.
- config1.txt          -->  Configuration file.
- industrial.cpp/.h    --> Industrial zone logic.
- main.cpp             --> Contains the main() function.
- region1.csv          --> Region layout file
- residential.cpp/.h   --> Residential zone logic.
- README.md            --> This file.

<br> 

## TODO
- Create design document that describes the process.
- Implement additional simulation features.
- Add unit tests for each simulation component.

<br>

## Requirements
- C/C++ compiler (e.g., g++, clang, MSVC)
- A terminal or IDE to compile and run the project.

<br> 

## Compilation Instructions
**Using g++:**
```bash
g++ *.cpp -o simcity
```

<br> 

## Running the Program
**After compiling, run the executable:**
```bash
./simcity
```

You will be prompted for:
1) The configuration file name.
2) The maximum time steps.
3) The refresh rate.

Then the program will read the region layout file (CSV format)
and start simulating the city growth.

<br> 

## ⭐ Contributing 
Contributions are welcome! If you find any issues or improvements, feel free to open an issue or submit a pull request.

<br> 

## Contact / Acknowledgments
All code is written by Oluwatobi Emmanuel.

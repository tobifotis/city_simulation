#ifndef CELL_H
#define CELL_H

struct Cell
{
    char type; // 'R', 'C', 'I', '-', 'T', '#', 'P'
    int population;
    int pollution;

    // Default values of each cell if none is passed
    Cell(char t = ' ', int pop = 0, int pol = 0) : type(t), population(pop), pollution(pol) // using initialization list
    {
    }
};

#endif
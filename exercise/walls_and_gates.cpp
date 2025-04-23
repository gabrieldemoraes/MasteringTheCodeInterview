//g++ -O3 walls_and_gates.cpp -o walls_and_gates.exe

#include "walls_and_gates.hpp"
#include <limits.h>

int main()
{
    int matrix[4][4] = { { INT_MAX, -1, 0, INT_MAX},
                           { INT_MAX, INT_MAX, INT_MAX, -1},
                           { INT_MAX, -1, INT_MAX, -1},
                           { 0, -1, INT_MAX, INT_MAX } };


    walls_and_gates(matrix);

    return 0;
}
//g++ -O3 number_of_minutes.cpp -o number_of_minutes.exe

#include "number_of_minutes.hpp"
#include <iostream>

int main() {
    std::vector<int> managersArray = {2, 2, 4, 6, -1, 4, 4, 5};
    std::vector<int> informTimeArray = {0, 0, 4, 0, 7, 3, 6, 0};

    int n = 8;
    int headID = 4;

    int totalMinutes = number_of_minutes(n, headID, managersArray, informTimeArray);
    std::cout << "Total Minutes: " << totalMinutes << std::endl;

    return 0;
}
//g++ -O3 trapping_rain_water.cpp -o trapping_rain_water.exe

#include "trapping_rain_water.hpp"
#include <iostream>
#include<vector>

int main()
{
    std::vector<int> array;
    // Case 1
    /*
    array.push_back(0);
    array.push_back(1);
    array.push_back(0);
    array.push_back(2);
    array.push_back(1);
    array.push_back(0);
    array.push_back(3);
    array.push_back(1);
    array.push_back(0);
    array.push_back(1);
    array.push_back(2);
    */

    //Case 2
    /*
    array.push_back(3);
    array.push_back(4);
    array.push_back(3);
    */
    //Case 3
    /*
    array.push_back(0);
    array.push_back(1);
    array.push_back(0);
    array.push_back(2);
    array.push_back(1);
    array.push_back(0);
    array.push_back(1);
    array.push_back(3);
    array.push_back(2);
    array.push_back(1);
    array.push_back(2);
    array.push_back(1);
    */
    //Case 4
    
    array.push_back(4);
    array.push_back(2);
    array.push_back(0);
    array.push_back(3);
    array.push_back(2);
    array.push_back(5);
    

    int result = trapped_rain_water_optmized(array);

    std::cout << result << std::endl;

    return 0;
}
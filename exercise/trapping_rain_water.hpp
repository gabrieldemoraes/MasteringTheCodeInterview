#include <vector>
#include <iostream>
#include <algorithm>

//TODO: colocar um generico aqui para aceitar qualquer tipo de array
int trapped_rain_water_brute_force(std::vector<int> &array)
{
    int total = 0, maxLeft = 0, maxRight = 0, currentHight = 0, currentWater = 0;

    for(int i = 0; i < array.size(); ++i)
    {
        currentHight = array[i];        
        for(int j = i -1; j >= 0; --j)
            maxLeft = std::max(array[j], maxLeft);

        for(int j = i + 1; j < array.size(); ++j)
            maxRight = std::max(array[j], maxRight);

        currentWater = std::min(maxLeft, maxRight) - currentHight;
        if(currentWater > 0)
            total += currentWater;   
        maxLeft = 0;
        maxRight = 0;
    }
    return total;
}

int trapped_rain_water_optmized(std::vector<int> &array)
{    
    int maxRight = 0, maxLeft = 0;
    int left = 0;
    int right = array.size() - 1;

    int total = 0, currentWater = 0;

    while (array[left] < array[right])
    {
        if(array[left] <= array[right])
        {            
            if(array[left] >= maxLeft)
                maxLeft = array[left];
            else
            {
                currentWater = maxLeft - array[left];
                total += currentWater;
            }
            ++left;
        }
        if(array[left] > array[right])
        {
            if(array[right] >= maxRight)
                maxRight = array[right];
            else
            {
                currentWater = maxRight - array[right];
                total += currentWater;
            }
            --right;
        }
    }
    return total;
}
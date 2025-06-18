#ifndef MINIMUM_COST_OF_CLIMBING_STAIRS_HPP
#define MINIMUM_COST_OF_CLIMBING_STAIRS_HPP

#include <vector>
#include <limits>

int min_cost(int i, std::vector<int> cost)
{
    if(i < 0) return 0;

    if(i == 0 || i == 1) return cost[i];

    return cost[i] + std::min(min_cost(i-1, cost), min_cost(i-2, cost));
}

int min_cost_climbing_stairs(std::vector<int> cost)
{
    auto n = cost.size();
    return std::min(min_cost(n-1, cost), min_cost(n-2, cost));
}


//USING DYNAMIC PROGRAMMING
int min_cost_dynamic_programming(int i, std::vector<int> cost, std::vector<int> dp)
{
    if(i < 0) return 0;

    if(i == 0 || i == 1) return cost[i];

    dp[i] = cost[i] + std::min(min_cost_dynamic_programming(i-1, cost, dp), min_cost_dynamic_programming(i-2, cost, dp));

    return dp[i];
}

int min_cost_climbing_stairs_dynamic_programming(std::vector<int> cost)
{
    auto n = cost.size();
    std::vector<int> dp;
    
    return std::min(min_cost_dynamic_programming(n-1, cost, dp), min_cost_dynamic_programming(n-2, cost, dp));
}

//USING DYNAMIC PROGRAMMING BOTTON UP
int min_cost_dynamic_programming_botton_up(std::vector<int> cost)
{
    auto n = cost.size();
    if(n == 0) return 0;
    if(n == 1) return cost[0];

    auto dpOne = cost[0];
    auto dpTwo = cost[1];

    for(int i = 2; i < n; ++i)
    {
        auto current = cost[i] + std::min(dpOne, dpTwo);
        dpOne = dpTwo;
        dpTwo = current;
    }
    return std::min(dpOne, dpTwo);
}


#endif
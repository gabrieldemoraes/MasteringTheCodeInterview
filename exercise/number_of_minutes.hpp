#ifndef NUMBER_OF_MINUTES_HPP
#define NUMBER_OF_MINUTES_HPP

#include <vector>
#include <map>

int DFS(int currentId, std::vector<std::vector<int>>& adjList, std::vector<int>& informTime)
{
    if(adjList[currentId].empty()) return 0;

    int maxTime = 0;

    auto subordinates = adjList[currentId];

    for (int subordinate : adjList[currentId]) {
        maxTime = std::max(maxTime, DFS(subordinate, adjList, informTime));
    }

    return maxTime + informTime[currentId];
}


int number_of_minutes(int n, int headId, std::vector<int> managers, std::vector<int> informTime)
{
    std::vector<std::vector<int>> adjList(n);

    for(int i = 0; i < n; ++i)
    {
        int manager = managers[i];
        if(manager != -1) adjList[manager].push_back(i);
    }
    return DFS(headId, adjList, informTime);
}


#endif
#ifndef BFS_IN_GRAPHS_HPP
#define BFS_IN_GRAPHS_HPP

#include <vector>
#include <queue>
#include <unordered_set>


std::vector<int> traversal_BFS(std::vector<std::vector<int>>& graph)
{
    std::queue<int> queue;
    std::vector<int> values;
    std::unordered_set<int> seen;

    queue.push(0);

    while(!queue.empty())
    {
        int vertex = queue.front();
        queue.pop();
        values.push_back(vertex);        
        seen.insert(vertex);
        const std::vector<int> &connections = graph[vertex];

        for(int i = 0; i < connections.size(); ++i)
        {
            int connection = connections[i];
            if(seen.find(connection) == seen.end())
                queue.push(connection);
        }
    }

    return values;
}

#endif
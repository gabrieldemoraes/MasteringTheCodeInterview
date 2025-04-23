#ifndef DFS_IN_GRAPHS
#define DFS_IN_GRAPHS

#include <vector>
#include <queue>
#include <unordered_set>

void traversal_DFS(int vertex, std::vector<std::vector<int>>& graph, std::vector<int>& values, std::unordered_set<int>& seen)
{
    values.push_back(vertex);
    seen.insert(vertex);
    const std::vector<int> &connections = graph[vertex];

    for(int i = 0; i < connections.size(); ++i)
    {
        int connection = connections[i];
        if(seen.find(connection) == seen.end())
            traversal_DFS(connection, graph, values, seen);
    }
}

#endif
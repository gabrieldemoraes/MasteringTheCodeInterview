#include <vector>
#include <queue>
#include <unordered_set>
#include <stack>

//BRUTE FORCE
bool can_finish_brute_force(int n, std::vector<std::vector<int>>& prerequisites)
{
    std::vector<std::vector<int>> adjList(n);

    for(const auto& i : prerequisites)
        adjList[i[1]].push_back(i[0]);
    
    for(int i = 0; i < n; ++i)
    {
        std::queue<int> q;
        std::unordered_set<int> seen;
        for(int v : adjList[i])
            q.push(v);

        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            seen.insert(current);
            if(current == i) return false;
            for(auto next : adjList[current])
            {
                if(seen.find(next) == seen.end())
                    q.push(next);
            }
        }
    }

    return true;
}

//OPTMIZED SOLUTION WITH ADJACENCY LIST
bool can_finish(int n, std::vector<std::vector<int>>& prerequisites)
{
    std::vector<int> inDegree(n, 0);
    std::vector<std::vector<int>> adjList(n);

    for(const auto& i : prerequisites)
    {
        ++inDegree[i[0]];
        adjList[i[1]].push_back(i[0]);
    }
    std::stack<int> s;

    for(int i = 0; i < inDegree.size(); ++i)
    {
        if(inDegree[i] == 0)
            s.push(i);
    }

    int count = 0;

    while(!s.empty())
    {
        auto current = s.top();
        s.pop();
        ++count;
        
        for(auto i : adjList[current])
        {
            --inDegree[i];
            if(inDegree[i] == 0)
                s.push(i);
        }
    }

    return count == n;
}

//OPTMIZED SOLUTION WITHOUT ADJACENCY LIST
bool can_finish_without_adj(int n, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> inDegree(n, 0);

    for (const auto& pair : prerequisites) 
        ++inDegree[pair[0]];

    std::stack<int> stack;

    for (int i = 0; i < inDegree.size(); i++) 
    {
        if (inDegree[i] == 0) 
            stack.push(i);
    }

    int count = 0;

    while (!stack.empty()) 
    {
        int current = stack.top();
        stack.pop();
        ++count;

        for (const auto& pair : prerequisites) 
        {
            if (pair[1] == current) 
            {
                --inDegree[pair[0]];
                if (inDegree[pair[0]] == 0) 
                    stack.push(pair[0]);
            }
        }
    }

    return count == n;
}

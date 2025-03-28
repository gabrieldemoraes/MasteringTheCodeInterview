#include <vector>
#include<queue>
#include <iostream>

#define ROW 4
#define COL 5

// Initialize direction vectors - UP, RIGHT, DOWN, LEFT
int directions[ROW][COL] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void BFS(int matrix[4][5], int row, int col, bool visit[4][5], std::vector<int> &values)
{
    std::queue<std::pair<int, int>> q;
    q.push({0, 0,});

    while(!q.empty())
    {
        auto currentPosition = q.front();
        q.pop();
        auto row = currentPosition.first;
        auto col = currentPosition.second;

        if(row < 0 || row >= ROW || col < 0 || col >= COL || visit[row][col]) continue;
        
        visit[row][col] = true;
        values.push_back(matrix[row][col]);

        for(int i = 0; i < 4; ++i)
        {
            auto currentDir = directions[i];
            q.push({row + currentDir[0], col + currentDir[1]});
        }
    }
}

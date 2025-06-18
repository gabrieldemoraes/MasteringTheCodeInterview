#ifndef ROTTING_ORANGES_HPP
#define ROTTING_ORANGES_HPP

#include <queue>

#define ROW 4
#define COL 5

// Initialize direction vectors - UP, RIGHT, DOWN, LEFT
int directions[ROW][COL] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


int oranges_rotting(int matrix[ROW][COL])
{
    int rotten = 2;
    int fresh = 1;
    std::queue<std::pair<int, int>> q;
    int freshOranges = 0;

    for(int row = 0; row < ROW; ++row)
    {
        for(int col = 0; col < COL; ++col)
        {
            if(matrix[row][col] == rotten) q.push({row, col});
            if(matrix[row][col] == fresh) ++freshOranges;
        }
    }

    int currentQueueSize = q.size();
    int minutes = 0;

    while(q.size() > 0)
    {
        if(currentQueueSize == 0)
        {
            ++minutes;
            currentQueueSize = q.size();
        }

        auto currentOrange = q.front();
        q.pop();
        auto row = currentOrange.first;
        auto col = currentOrange.second;

        for(int i = 0; i < 4; ++i)
        {
            auto currentDirection = directions[i];
            auto nextRow = currentDirection[0] + row;
            auto nextCol = currentDirection[1] + col;
            if(nextRow < 0 || nextRow >= ROW || nextRow < 0 || nextCol >= COL) continue;

            if(matrix[nextRow][nextCol] == fresh)
            {
                matrix[nextRow][nextCol] = 2;\
                --freshOranges;
                q.push({nextRow, nextCol});
            } 
        }
    }
    if(freshOranges > 0) return -1;
    return minutes;

}

#endif
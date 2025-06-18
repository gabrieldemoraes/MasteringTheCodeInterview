#ifndef NUMBER_OF_ISLANDS_HPP
#define NUMBER_OF_ISLANDS_HPP
#include <queue>

#define ROW 4
#define COL 5

// Initialize direction vectors - UP, RIGHT, DOWN, LEFT
int directions[ROW][COL] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


int number_of_islands_BFS(int matrix[ROW][COL])
{
    if(matrix == 0) return 0;

    int islandCount = 0;
    std::queue<std::pair<int, int>> q;
    
    for(int row = 0; row < ROW; ++row)
    {
        for(int col = 0; col < COL; ++col)
        {
            if(matrix[row][col] == 1)
            {
                ++islandCount;
                matrix[row][col] = 0;
                q.push({row, col});
            }
            while(q.size())
            {
                std::pair<int, int> currentPos = q.front();
                q.pop();
                auto currentRow = currentPos.first;
                auto currentCol = currentPos.second; 

                for(int i = 0; i < 4; ++i)
                {
                    auto currentDir = directions[i];
                    auto nextRow = currentRow + currentDir[0];
                    auto nextCol = currentCol + currentDir[1];
                    if(nextRow < 0 || nextRow >= ROW || nextCol < 0 || nextCol >= COL) continue;
                    if(matrix[nextRow][nextCol] == 1)
                    {
                        q.push({nextRow, nextCol});
                        matrix[nextRow][nextCol] = 0;
                    }
                }
            }
        }
    }
    return islandCount;
}

void DFS(int matrix[ROW][COL], int currentRow, int currentCol) {
    if (currentRow < 0 || currentRow >= ROW || currentCol < 0 || currentCol >= COL) {
        return;
    }

    if (matrix[currentRow][currentCol] == 1) {
        matrix[currentRow][currentCol] = 0;

        for (int i = 0; i < 4; ++i) {
            auto currentDir = directions[i];
            int row = currentDir[0];
            int col = currentDir[1];
            DFS(matrix, currentRow + row, currentCol + col);
        }
    }
}

int number_of_islands_DFS(int matrix[ROW][COL]) {

    int islandCount = 0;

    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            if (matrix[row][col] == 1) {
                ++islandCount;
                DFS(matrix, row, col);
            }
        }
    }

    return islandCount;
}
#endif
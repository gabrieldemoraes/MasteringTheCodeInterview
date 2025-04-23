

#define ROW 4
#define COL 4

// Initialize direction vectors - UP, RIGHT, DOWN, LEFT
int directions[ROW][COL] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void DFS(int matrix[ROW][COL], int row, int col, int currentStep)
{
    if(row < 0 || row > ROW || col < 0 || col > COL || currentStep > matrix[ROW][COL])
    {
        return;
    }
    matrix[row][col] = currentStep;
    for(int i = 0; i < 4; ++i)
    {
        auto currentDir = directions[i];
        DFS(matrix, row + currentDir[0], col + currentDir[1], ++currentStep);
    }
}

void walls_and_gates(int matrix[ROW][COL])
{
    for(int i = 0; i < ROW; ++i)
    {
        for(int j = 0; j < COL; ++j)
        {
            if(matrix[i][j] == 0)
            {
                DFS(matrix, i, j, 0);
            }
        }
    }
}




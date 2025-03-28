#include <vector>

#define ROW 4
#define COL 5

// Initialize direction vectors - UP, RIGHT, DOWN, LEFT
int directions[ROW][COL] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void DFS(int matrix[4][5], int row, int col, bool visit[4][5], std::vector<int> &values)
{
    if(row < 0 || col < 0 || row >= ROW || col >= COL || visit[row][col]) return;

    values.push_back(matrix[row][col]);

    visit[row][col] = true;

    for(int i = 0; i < 4; ++i)
    {
        auto currentDir = directions[i];

        DFS(matrix, row + currentDir[0], col + currentDir[1], visit, values);
    }
}

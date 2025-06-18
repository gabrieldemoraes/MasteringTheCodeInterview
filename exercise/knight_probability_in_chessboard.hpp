#ifndef KNIGHT_PROBABILITY_IN_CHESSBOARD
#define KNIGHT_PROBABILITY_IN_CHESSBOARD

#include<vector>

std::vector<std::vector<int>> directions = {{-2,-1}, {-2,1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, 2}};

double knight_probability(int n, int k, int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= n) return 0;
    
    if(k ==0) return 1;

    double res = 0;

    for(const auto& dir : directions)
    {
        res += knight_probability(n, k-1, r + dir[0], c + dir[1]) / 8;
    }
    
    return res;
}

std::vector<std::vector<std::vector<double>>> dp;
double recursive(int n, int k, int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= n) return 0;
    
    if(k ==0) return 1;

    double res = 0.0;
    for(const auto& dir : directions)
    {
        res += recursive(n, k-1, r + dir[0], c + dir[1]) / 8.0;
    }

    dp[r][c][k] = res;
    return res;
}

double knight_probability_memoizing(int n, int k, int r, int c)
{
    dp.assign(n, std::vector<std::vector<double>>(n, std::vector<double>(k+1, -1.0)));
    return recursive(n, k, r, c);
}

double knight_probability_botton_up_tabulation(int n, int k, int r, int c)
{
    std::vector<std::vector<std::vector<double>>> dp(k + 1, std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0)));
    dp[0][r][c] = 1.0;

    for(int step = 1; step <= k; ++step)
    {
        for(int row = 0; row < n; ++row)
        {
            for(int col = 0; col < n; ++col)
            {
                for(const auto& dir : directions)
                {
                    int previousRow = row + dir[0];
                    int previousCol = col + dir[1];
                    if(previousRow >= 0 && previousRow < n &&
                       previousCol >= 0 && previousCol < n)
                    {
                        dp[step][row][col] += dp[step - 1][previousRow][previousCol]/8.0;
                    }
                }
            }
        }
    }
    double res = 0.0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            res += dp[k][i][j];
        }
    }
    return res;
}

double knight_probability_botton_up_tabulation_oprimization(int N, int K, int r, int c) {
    std::vector<std::vector<double>> prevDp(N, std::vector<double>(N, 0.0));
    std::vector<std::vector<double>> nextDp(N, std::vector<double>(N, 0.0));

    prevDp[r][c] = 1.0;

    for (int step = 1; step <= K; step++) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                for (const auto& dir : directions) {
                    int prevRow = row + dir[0];
                    int prevCol = col + dir[1];
                    if (prevRow >= 0 && prevRow < N && prevCol >= 0 && prevCol < N) {
                        nextDp[row][col] += prevDp[prevRow][prevCol] / 8.0;
                    }
                }
            }
        }
        prevDp = nextDp;
        nextDp.assign(N, std::vector<double>(N, 0.0));
    }

    double res = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res += prevDp[i][j];
        }
    }

    return res;
}

#endif

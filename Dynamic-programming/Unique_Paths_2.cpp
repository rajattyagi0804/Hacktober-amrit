/*
    We have to find the number of paths to reach from (0 , 0) --> (N , M)
    considering obstacles in the grid.
    We can use the same approach as in Unique Paths 1. Just a small modification
    when we encounter an obstacle.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define SIZE(v) (int)v.size()
#define MOD 1000000007
#define TC(t) while (t--)

int solve_rec(int row, int col, int rowLimit, int colLimit, vector<vector<int>> &mat)
{
    if (row == rowLimit && colLimit == col)
    {
        return 1;
    }

    if (row > rowLimit || col > colLimit || mat[row][col] == -1)
    {
        return 0;
    }

    int right = solve_rec(row, col + 1, rowLimit, colLimit, mat);
    int down = solve_rec(row + 1, col, rowLimit, colLimit, mat);

    return (right + down) % MOD;
}

int solve_memoIzation(int row, int col, int rowLimit, int colLimit, vector<vector<int>> &mat,
                      vector<vector<int>> &dp)
{
    if (row == rowLimit && colLimit == col)
    {
        return 1;
    }

    if (row > rowLimit || col > colLimit || mat[row][col] == -1)
    {
        return 0;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int right = solve_memoIzation(row, col + 1, rowLimit, colLimit, mat, dp);
    int down = solve_memoIzation(row + 1, col, rowLimit, colLimit, mat, dp);

    return dp[row][col] = (right + down) % MOD;
}

int tabulation(vvi &mat, int n, int m)
{
    vvi dp(n, vi(m, 0));

    dp[0][0] = 1;

    for (int rows = 0; rows < n; rows++)
    {
        for (int cols = 0; cols < m; cols++)
        {
            if (rows == 0 && cols == 0)
            {
                dp[0][0] = 1;
                continue;
            }

            else if (mat[rows][cols] == -1)
            {
                dp[rows][cols] = 0;
                continue;
            }
            else
            {
                int down = rows > 0 ? dp[rows - 1][cols] : 0;
                int right = cols > 0 ? dp[rows][cols - 1] : 0;

                dp[rows][cols] = (down + right) % MOD;
            }
        }
    }

    return dp[n - 1][m - 1] % MOD;
}

int tabulation_2(vvi &mat)
{
    int N = mat.size();
    int M = SIZE(mat[0]);

    vvi dp(N, vi(M, 0));

    // Base Case
    dp[N - 1][M - 1] = 1;

    for (int row = N - 1; row >= 0; row--)
    {
        for (int col = M - 1; col >= 0; col--)
        {
            if (row == N - 1 && col == M - 1 && mat[row][col] != -1)
            {
                dp[row][col] = 1;
                continue;
            }

            else if (mat[row][col] == -1)
            {
                dp[row][col] = 0;
            }
            else
            {
                int up = row < (N - 1) ? dp[row + 1][col] : 0;
                int left = col < (M - 1) ? dp[row][col + 1] : 0;

                dp[row][col] = (up + left) % MOD;
            }
        }
    }

    return dp[0][0];
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = solve_memoIzation(0, 0, n - 1, m - 1, mat, dp);
    return ans % MOD;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// m1 -> by dp
int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
{

    if (i >= m || j >= n)
    {
        return 0;
    }
    if (i == m - 1 && j == n - 1)
    {
        return dp[i][j] = 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    return dp[i][j] = solve(i + 1, j, m, n, dp) + solve(i, j + 1, m, n, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solve(0, 0, m, n, dp);
}

// m2->by formula

int uniquePaths(int m, int n)
{
    int N = m + n - 2;
    int r = m - 1;
    double res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}

int main()
{
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int solvebydp(int coins[], int M, int V, vector<int> &dp)
{

    if (V < 0)
    {
        return INT_MAX;
    }

    if (V == 0)
    {
        return dp[V] = 0;
    }
    if (dp[V] != -1)
    {
        return dp[V];
    }

    int mini = INT_MAX;
    for (int i = 0; i < M; i++)
    {
        int ans = solvebydp(coins, M, V - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return dp[V] = mini;
}
int minCoins(int coins[], int M, int V)
{
    vector<int> dp(V + 1, -1);
    int ans = solvebydp(coins, M, V, dp);
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}
int main()
{
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(vector<int> &values, vector<int> &weights, int index, int leftW, vector<vector<int>> &dp)
{
    if (index == values.size() || leftW == 0)
    {
        return 0;
    }
    if (dp[index][leftW] != -1)
    {
        return dp[index][leftW];
    }
    int ans = -1;

    // taking it is possible
    if (leftW - weights[index] >= 0)
    {
        ans = max(ans, solve(values, weights, index + 1, leftW - weights[index], dp) + values[index]);
    }

    // ignoring
    ans = max(ans, solve(values, weights, index + 1, leftW, dp));

    return dp[index][leftW] = ans;
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(1002, vector<int>(1002, -1));
    return solve(values, weights, 0, w, dp);
}       
int main()
{
    return 0;
}
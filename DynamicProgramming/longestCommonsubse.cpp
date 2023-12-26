#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int dp[1001][1001];
    int solve(int i, int j, string &text1, string &text2)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = solve(i - 1, j, text1, text2);
        ans = max(ans, solve(i, j - 1, text1, text2));
        ans = max(ans, solve(i - 1, j - 1, text1, text2) + (text1[i] == text2[j]));
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(text1.size() - 1, text2.size() - 1, text1, text2);
    }
};
int main()
{
    return 0;
}
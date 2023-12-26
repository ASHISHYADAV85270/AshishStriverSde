#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int dp[2507];
    int solve(int index, vector<int> &nums)
    {
        if (index == nums.size())
        {
            return 0;
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }
        int ans = 1;
        for (int i = index + 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[index])
            {
                ans = max(ans, solve(i, nums) + 1);
            }
        }
        return dp[index] = ans;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};

int main()
{
    return 0;
}
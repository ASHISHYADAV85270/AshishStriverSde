#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int largestsum = nums[0];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += nums[i];
            largestsum = max(ans, largestsum);
            if (ans < 0)
            {
                ans = 0;
            }
        }
        return largestsum;
    }
};

int main()
{
    return 0;
}
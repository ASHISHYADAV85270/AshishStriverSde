#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    // m1 : brute force
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int ans = -1;
        for (auto &val : mp)
        {
            if (floor(n / 2) < val.second)
            {
                ans = val.first;
            }
        }
        return ans;
    }

    // m2 : optimised approach -> moores voiting
    int majorityElement(vector<int> &nums)
    {
        int ele;
        int ct = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ct == 0)
            {
                ele = nums[i];
                ct = 1;
            }
            else if (ele == nums[i])
            {
                ct++;
            }
            else
            {
                ct--;
            }
        }

        // if in questionb it is given that it is forsure that there is ele by count > n/2 then return ele other wise verify it

        // checking if the ele left is majority ele or not
        ct = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == ele)
            {
                ct++;
            }
        }
        if (ct > floor(nums.size() / 2))
        {
            return ele;
        }
        return -1;
    }
};
int main()
{
    return 0;
}
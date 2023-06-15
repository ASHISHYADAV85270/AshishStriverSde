#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// m1
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
        if (mp[nums[i]] == (floor(n / 3) + 1))
        {
            ans.push_back(nums[i]);
            if (ans.size() == 2)
            {
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
// m2
vector<int> majorityElementOptimised(vector<int> &nums)
{
    int ele1, ele2, ct1 = 0, ct2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ct1 == 0 && nums[i] != ele2)
        {
            ele1 = nums[i];
            ct1 = 1;
        }
        else if (ele1 == nums[i])
        {
            ct1++;
        }
        else if (ct2 == 0 && nums[i] != ele1)
        {
            ele2 = nums[i];
            ct2 = 1;
        }
        else if (ele2 == nums[i])
        {
            ct2++;
        }
        else
        {
            ct1--;
            ct2--;
        }
    }
    ct1 = ct2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ele1 == nums[i])
        {
            ct1++;
        }
        if (ele2 == nums[i])
        {
            ct2++;
        }
    }

    vector<int> ans;
    if (ct1 > floor(nums.size() / 3))
    {
        ans.push_back(ele1);
    }

    if (ct2 > floor(nums.size() / 3))
    {
        ans.push_back(ele2);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    return 0;
}
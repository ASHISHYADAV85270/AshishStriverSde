#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// m1-> using binary search
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> store = nums;
    sort(nums.begin(), nums.end());
    int lower_index = 0, higher_index = n - 1;
    while (lower_index < higher_index)
    {
        if (nums[lower_index] + nums[higher_index] == target)
        {
            break;
        }
        else if (nums[lower_index] + nums[higher_index] > target)
        {
            higher_index--;
        }
        else
        {
            lower_index++;
        }
    };

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (store[i] == nums[lower_index])
        {
            ans.push_back(i);
        }
        else if (store[i] == nums[higher_index])
        {
            ans.push_back(i);
        }
        if (ans.size() == 2)
        {
            break;
        }
    }

    return ans;
}

// m2-> using hashtable
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        int firstele = nums[i];
        if (m.end() != m.find(target - firstele))
        {
            return {m[target - firstele], i};
        }
        else
        {
            m[firstele] = i;
        }
    }

    return {};
}

int main()
{
    return 0;
}
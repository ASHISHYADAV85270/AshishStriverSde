#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// m1
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    // point to be sstarted ->n-k
    k = k % n;
    for (int i = n - k; i < n; i++)
    {
        ans.push_back(nums[i]);
    }
    for (int i = 0; i < n - k; i++)
    {
        ans.push_back(nums[i]);
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = ans[i];
    }
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}

// m2 optimised approach
void rotateoptimised(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}
/*
 */

int main()
{
    cout << 7 % 7;

    return 0;
}
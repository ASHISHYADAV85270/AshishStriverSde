#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        // CHECK FOR BREAK POINT
        int index = -1;
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                index = i - 1;
                break;
            }
        }
        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (int i = n - 1; i > index; i--)
            {
                if (nums[index] < nums[i])
                {
                    swap(nums[index], nums[i]);
                    break;
                }
            }

            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};
int main()
{
    return 0;
}
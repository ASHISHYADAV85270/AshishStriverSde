#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        };
        int new_slow = nums[0];

        while (new_slow != slow)
        {
            new_slow = nums[new_slow];
            slow = nums[slow];
        };
        return nums[slow];
    }
};

int main()
{
    return 0;
}
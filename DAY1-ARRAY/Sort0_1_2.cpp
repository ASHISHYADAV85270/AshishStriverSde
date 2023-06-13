#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    /* 0 to low-1 --->0
       low to mid-1--->1
       mid to high --> unsorted
       high+1 --->n-1 2
     */
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        };
    }
};
int main()
{
    return 0;
}
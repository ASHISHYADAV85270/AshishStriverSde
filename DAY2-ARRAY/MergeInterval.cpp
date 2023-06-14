#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {

            if (ans.size() != 0 && ans.back()[1] >= intervals[i][0])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else if (ans.size() == 0 || ans.back()[1] < intervals[i][0])
            {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
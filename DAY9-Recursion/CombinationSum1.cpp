#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &candidates, int target, vector<int> &curr, int sum, int index, vector<vector<int>> &ans)
    {
        if (index == candidates.size())
        {
            if (sum == target)
            {
                ans.push_back(curr);
            }
            return;
        }

        if (sum > target)
        {
            return;
        }

        // ignoring element
        solve(candidates, target, curr, sum, index + 1, ans);

        // taking ele
        curr.push_back(candidates[index]);
        solve(candidates, target, curr, sum + candidates[index], index, ans);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(candidates, target, curr, 0, 0, ans);
        return ans;
    }
};
int main()
{
    return 0;
}
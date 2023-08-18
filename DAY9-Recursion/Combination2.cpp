#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    void solve(vector<int> &candidates, int target, vector<int> &curr, int sum, int index, vector<vector<int>> &ans)
    {

        if (sum == target)
        {
            ans.push_back(curr);
            return;
        }

        if (sum > target)
        {
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i != index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            // taking ele
            curr.push_back(candidates[i]);
            solve(candidates, target, curr, sum + candidates[i], i + 1, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, curr, 0, 0, ans);
        return ans;
    }
};
int main()
{
    return 0;
}
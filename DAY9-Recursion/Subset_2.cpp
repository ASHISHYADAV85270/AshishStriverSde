#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// method1 ..here we are using extra space
void solve(set<vector<int>> &ans, vector<int> curr, int index, vector<int> &arr)
{
    if (index == arr.size())
    {
        sort(curr.begin(), curr.end());
        ans.insert(curr);
        return;
    }

    // ignoring the element
    solve(ans, curr, index + 1, arr);

    // taking ele
    curr.push_back(arr[index]);
    solve(ans, curr, index + 1, arr);
    curr.pop_back();
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> ans;
    vector<int> curr;
    vector<vector<int>> final_ans;
    solve(ans, curr, 0, nums);
    for (auto &val : ans)
    {
        final_ans.push_back(val);
    }
    return final_ans;
}

// method 2
void solve(vector<vector<int>> &ans, vector<int> &curr, int index, vector<int> &arr)
{
    ans.push_back(curr);
    for (int i = index; i < arr.size(); i++)
    {
        if (i != index && arr[i - 1] == arr[i])
        {
            continue;
        }

        // taking ele
        curr.push_back(arr[i]);
        solve(ans, curr, i + 1, arr);
        curr.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> curr;
    sort(nums.begin(), nums.end());
    solve(ans, curr, 0, nums);
    return ans;
}

int main()
{
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void solve(vector<int> &ans, int sum, int index, vector<int> &arr)
{
    if (index == arr.size())
    {
        ans.push_back(sum);
        return;
    }
    // ignoring the element
    solve(ans, sum, index + 1, arr);
    // taking ele
    solve(ans, sum + arr[index], index + 1, arr);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    solve(ans, 0, 0, arr);
    return ans;
}

int main()
{
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // m -> no of total stud
    // n -> no of candies
    int ans = INT_MAX;
    int starting_index = 0;
    int end_index = m - 1;
    sort(a.begin(), a.end());
    for (end_index = m - 1; end_index < n; end_index++, starting_index++)
    {
        int curr_diff = a[end_index] - a[starting_index];
        ans = min(ans, curr_diff);
    }
    return ans;
}
int main()
{
    return 0;
}
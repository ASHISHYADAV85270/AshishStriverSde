// longest subaray with given sum k
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// m1 -> it will give tle ->o(n2) sc->o(1)
int lenOfLongSubarr(int A[], int N, int K)
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += A[j];
            if (sum == K)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

// m2->  reverse eng ===> using prefix sum and hashing
// tc->nlogn OR O(N*N)  SC->O(n)
// it is most optimised for negativs and positives......but it is not the most optimised for only positives
int lenOfLongSubarr(int A[], int N, int K)
{
    unordered_map<long long int, int> mp;
    int ans = 0;
    long long int prefix_sum = 0;
    for (int i = 0; i < N; i++)
    {
        prefix_sum += A[i];
        if (prefix_sum == K)
        {
            ans = max(ans, i + 1);
        }
        if (mp.find(prefix_sum - K) != mp.end())
        {
            ans = max(ans, i - mp[prefix_sum - K]);
        }

        // agr y condition nhi likhi too negatives vaale case mai y kaam nhi krega
        if (mp.find(prefix_sum) == mp.end())
        {
            mp[prefix_sum] = i;
        }
    }
    return ans;
}

// m3-> best optimesed code for all positives -->USING TWO POINTER AND GREEDY APP
// unordered map give o(n) in the worst case
int getLongestSubarray(vector<int> &nums, int k)
{
    int prefix_Sum = nums[0];
    int N = nums.size();
    int ans = 0;
    int i = 0, j = 0;
    while (j < N)
    {
        while (i <= j && prefix_Sum > k)
        {
            prefix_Sum -= nums[i];
            i++;
        };
        if (prefix_Sum == k)
        {
            ans = max(ans, j - i + 1);
        }
        j++;
        if (j < N)
        {
            prefix_Sum += nums[j];
        }
    };

    return ans;
}
int main()
{
    return 0;
}
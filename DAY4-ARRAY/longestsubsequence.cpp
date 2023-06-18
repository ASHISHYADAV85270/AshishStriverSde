#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return n;
        }
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int ans = 1;
        int lastsmalest = INT_MIN;
        for (int i = 0; i < n; i++)
        {

            if (nums[i] - 1 == lastsmalest)
            {
                cnt++;
                ans = max(ans, cnt);
                lastsmalest = nums[i];
            }
            else if (nums[i] != lastsmalest)
            {
                cnt = 1;
                lastsmalest = nums[i];
            }
        }

        return ans;
    }

    // m2=> assuming set is taking 0(1)  so tc-> 2n + n ==3n sc->o(n)
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return n;
        }
        int ans = 0;
        unordered_set<int> s;
        // n
        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }
        // 2n not n2
        for (auto &val : s)
        {
            if (s.find(val - 1) == s.end())
            {

                int cnt = 1;
                int starting = val;
                // it is not n because we are not iterating all the time
                while (s.find(starting + 1) != s.end())
                {
                    cnt++;
                    starting++;
                };
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
int main()
{
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// tc->o(nlogn) sc->o(n)
class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(make_pair(start[i], end[i]));
        }
        sort(v.begin(), v.end(), cmp);

        int ct = 1;
        int prev_e = v[0].second;

        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= prev_e)
            {
                ct++;
                prev_e = v[i].second;
            }
        }
        return ct;
    }
};
int main()
{
    return 0;
}
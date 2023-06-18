#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<long long int, int> mp;
    long long int prefix_xor = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        prefix_xor ^= arr[i];
        long long int req_xor = prefix_xor ^ x;
        if (prefix_xor == x)
        {
            ans++;
        }
        if (mp.find(req_xor) != mp.end())
        {
            ans += mp[req_xor];
        }
        mp[prefix_xor]++;
    }
    return ans;
}
int main()
{
    cout << (0 ^ 3);
    return 0;
}
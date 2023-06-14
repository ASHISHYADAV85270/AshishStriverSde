#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// method one ->hashing
vector<int> repeatedNumber(const vector<int> &A)
{
    int n = A.size();

    vector<int> vis(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        vis[A[i]]++;
    }

    int twice, missing;
    for (int i = 1; i < n + 1; i++)
    {
        if (vis[i] == 2)
        {
            twice = i;
        }
        if (vis[i] == 0)
        {
            missing = i;
        }
    }
    return {twice, missing};
}

// mehtod 2 using maths
vector<int> mathssolve(vector<int> A)
{
    long long n = A.size();
    // x-> repeat y-> missing
    // S-Sn=X-Y
    // S2-S2n=X2 - Y2;

    long long int SN = (n * (n + 1)) / 2;
    long long int S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    long long int S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += A[i];
        S2 += (long long)A[i] * (long long)A[i];
    }
    long long int val1 = S - SN; // x-y
    long long int val2 = S2 - S2N;
    val2 = val2 / val1; // x+y
    long long int x = (val1 + val2) / 2;
    long long int y = x - val1;
    return {(int)x, (int)y};
}

int main()
{
    return 0;
}
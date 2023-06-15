#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// m1 => it gives tle
double myPow(double x, int n)
{
    double ans = 1.0;
    long long int N = n; // over flow handle krne kai liye hai long long int
    if (n < 0)
    {
        N = -1 * n;
    }

    for (int i = 0; i < abs(n); i++)
    {
        if (n < 0)
        {
            ans /= x;
        }
        else
        {
            ans = ans * x;
        }
    }
    return ans;
}
// m2
/*
2^10 = (2*2)^5=(4)^5=4*(4)^4=4*(16)^2=4*(256)^1=ans

if n== even n=n/2 and x=x*x

if n=odd n=n-1 and ans=ans*x;


*/
double myPow(double x, int n)
{
    double ans = 1.0;
    long long int N = n; // over flow handle krne kai liye hai long long int
    if (N < 0)
    {
        N = -1 * N;
    }

    while (N > 0)
    {
        if (N % 2 == 0)
        {
            x = x * x;
            N = N / 2;
        }
        else
        {
            N = N - 1;
            ans = ans * x;
        }
    };

    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }

    return ans;
}
int main()
{
    return 0;
}
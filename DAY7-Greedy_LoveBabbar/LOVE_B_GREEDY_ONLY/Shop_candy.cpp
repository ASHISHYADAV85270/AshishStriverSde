#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N);

    int mini = 0;
    int buy = 0;
    int fre_candy = N - 1;

    while (buy <= fre_candy)
    {
        mini = mini + candies[buy++];
        fre_candy = fre_candy - K;
    };

    int maxi = 0;
    buy = N - 1;
    fre_candy = 0;

    while (fre_candy <= buy)
    {
        maxi = maxi + candies[buy--];
        fre_candy = fre_candy + K;
    };

    return {mini, maxi};
}
int main()
{
    return 0;
}
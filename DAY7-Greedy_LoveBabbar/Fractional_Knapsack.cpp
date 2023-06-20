#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Item
{
    int value;
    int weight;
};
double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double, int>> v;
    for (int i = 0; i < n; i++)
    {

        double perunitvalue = ((double)arr[i].value) / arr[i].weight;
        v.push_back(make_pair(perunitvalue, arr[i].weight));
    }

    sort(v.begin(), v.end());

    double ans = 0.0;

    for (int i = n - 1; i >= 0; i--)
    {

        if (v[i].second > W)
        {

            ans = ans + 1.0 * v[i].first * W;
            W = 0;
        }
        else
        {

            ans = ans + v[i].first * 1.0 * v[i].second;
            W = W - v[i].second;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
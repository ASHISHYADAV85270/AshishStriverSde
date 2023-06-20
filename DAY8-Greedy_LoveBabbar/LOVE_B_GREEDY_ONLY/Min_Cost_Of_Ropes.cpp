#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long minimum_cost = 0;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() != 1)
    {
        long long first_smallest = pq.top();
        pq.pop();
        long long second_smallest = pq.top();
        pq.pop();
        long long there_sum = first_smallest + second_smallest;
        minimum_cost += there_sum;
        pq.push(there_sum);
    };
    return minimum_cost;
}
int main()
{
    return 0;
}
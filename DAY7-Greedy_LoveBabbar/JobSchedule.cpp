#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);
    int count = 0;
    int totalprofit = 0;
    vector<int> schedule(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int currId = arr[i].id;
        int curr_Dead = arr[i].dead;
        int curr_Profit = arr[i].profit;

        for (int k = curr_Dead; k > 0; k--)
        {
            if (schedule[k] == -1)
            {
                schedule[k] = currId;
                totalprofit += curr_Profit;
                count++;
                break;
            }
        }
    }
    return {count, totalprofit};
}
int main()
{
    return 0;
}
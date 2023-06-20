#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1
int minimumDays(int S, int N, int M)
{
    int sunday = S / 7;
    int buydays = S - sunday;
    int total_food_to_survive = M * S;
    int ans;
    if (total_food_to_survive % N == 0)
    {
        ans = total_food_to_survive / N;
    }
    else
    {
        ans = (total_food_to_survive / N) + 1;
    }

    if (ans <= buydays)
    {
        return ans;
    }
    return -1;
}
int main()
{
    return 0;
}
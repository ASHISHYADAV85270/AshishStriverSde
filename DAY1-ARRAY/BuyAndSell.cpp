#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            buy = min(buy, prices[i]);
            int currPro = prices[i] - buy;
            profit = max(profit, currPro);
        }
        return profit;
    }
};
int main()
{
    return 0;
}
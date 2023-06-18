#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    // m1 brute force  tc-> n4 sc-> 4(element)+(ele)
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        int currsum = nums[i] + nums[j] + nums[k] + nums[l];
                        if (currsum == target)
                        {
                            vector<int> curr = {nums[i], nums[j], nums[k], nums[l]};
                            sort(curr.begin(), curr.end());
                            temp.insert(curr);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;
    }

    // m2 -> by reducing one loop and using hash map TC->N3LOGN
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                unordered_map<long long int, long long int> mp;
                for (int k = j + 1; k < n; k++)
                {

                    long long int currsum = nums[i] + nums[j];
                    currsum += nums[k];
                    long long int temptarget = target - currsum;

                    if (mp.find(temptarget) != mp.end())
                    {
                        vector<int> curr = {nums[i], nums[j], nums[k], (int)temptarget};
                        sort(curr.begin(), curr.end());
                        temp.insert(curr);
                    }
                    mp[nums[k]]++;
                }
            }
        }
        vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;
    }

    // M3 USING two pointer approach
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int low = j + 1;
                int high = n - 1;
                long long int currsum = nums[i] + nums[j];
                long long int temptarget = target - currsum;
                while (low < high)
                {
                    if (nums[low] + nums[high] == temptarget)
                    {
                        vector<int> curr = {nums[i], nums[j], nums[low], nums[high]};
                        ans.push_back(curr);
                        low++;
                        high--;
                        // jbtk same hai aagai bd tai rhoo
                        while (low < high && nums[low] == nums[low - 1])
                        {
                            low++;
                        };
                        while (low < high && nums[high + 1] == nums[high])
                        {
                            high--;
                        };
                    }
                    else if (nums[low] + nums[high] > temptarget)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                };
                while (j < n - 1 && nums[j] == nums[j + 1])
                {
                    j++;
                };
            }
            while (i < n - 2 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }

        return ans;
    }
};
int main()
{
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    // m1-> tle for n3
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        map<vector<int>, int> mp;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {

                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> curr;
                        curr.push_back(nums[i]);
                        curr.push_back(nums[j]);
                        curr.push_back(nums[k]);
                        sort(curr.begin(), curr.end());
                        mp[curr]++;
                    }
                }
            }
        }
        vector<vector<int>> ans;

        for (auto &val : mp)
        {
            ans.push_back(val.first);
        }
        return ans;
    }

    // M2-> IT ALSO GIVES TLE but it is almost n2logn ,,, but we want n2
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> m;
            for (int j = i + 1; j < n; j++)
            {
                int target = -(nums[i] + nums[j]);
                if (m.find(target) != m.end())
                {
                    vector<int> curr = {nums[i], nums[j], target};
                    sort(curr.begin(), curr.end());
                    st.insert(curr);
                }
                m[nums[j]]++;
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // m3 === 2 pointer app
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = n - 1;
            int target = -1 * nums[i];

            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    vector<int> crr = {nums[i], nums[j], nums[k]};
                    ans.push_back(crr);
                    j++;
                    k--;
                    // jbtk same hai aagai bd tai rhoo
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    };
                    while (j < k && nums[k + 1] == nums[k])
                    {
                        k--;
                    };
                }
                else if (nums[j] + nums[k] > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            };
            while (i < n - 1 && nums[i] == nums[i + 1])
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
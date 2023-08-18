#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool checkPalindrome(string str, int start, int end)
    {
        if (str.size() == 0)
        {
            return false;
        }
        int left = start, right = end;
        while (left <= right)
        {
            if (str[left++] != str[right--])
            {
                return false;
            }
        };
        return true;
    }

    void solve(vector<vector<string>> &ans, int index, vector<string> str, string s)
    {
        if (index == s.length())
        {
            ans.push_back(str);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (checkPalindrome(s, index, i))
            {
                str.push_back(s.substr(index, i - index + 1));
                solve(ans, i + 1, str, s);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> str;

        solve(ans, 0, str, s);
        return ans;
    }
};
int main()
{
    return 0;
}
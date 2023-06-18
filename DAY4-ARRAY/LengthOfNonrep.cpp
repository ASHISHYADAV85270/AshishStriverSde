// lenght of longest non repaeating substring
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// m1-> brute force method
int lengthOfLongestSubstring(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        set<char> st;
        int maxlen = 0;

        for (int j = i; j < n; j++)
        {
            char curr_char = s[j];
            cout << curr_char << " ";
            if (st.find(curr_char) == st.end())
            {
                maxlen++;
                st.insert(curr_char);
                ans = max(maxlen, ans);
            }
            else
            {
                break;
            }
        }
        cout << endl;
    }
    return ans;
}

// m2-> best solution tc->o(n)
// striver
int lengthOfLongestSubstring(string s)
{
    int left = 0;
    int ans = 0;
    vector<int> vt(256, -1);
    int right = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (vt[s[i]] != -1)
        {
            left = max(vt[s[i]] + 1, left); // to jada index pai hoga usai lengai
        }
        vt[s[i]] = i;
        ans = max(ans, i - left + 1);
    }

    return ans;
}

int main()
{
    return 0;
}
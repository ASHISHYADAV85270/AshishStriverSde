#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int expandFromCentre(string s, int i, int j)
    {
        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return j - i - 1;
    }
    string longestPalindrome(string s)
    {
        int startIndex = 0, endIndex = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = expandFromCentre(s, i, i);
            int len2 = expandFromCentre(s, i, i + 1);
            int maxlen = max(len1, len2);
            if (endIndex - startIndex < maxlen)
            {
                startIndex = i - ((maxlen - 1) / 2);
                endIndex = i + (maxlen / 2);
            }
        }
        return s.substr(startIndex, endIndex + 1);
    }
};
int main()
{
    Solution s;
    cout << "abbab\n";
    cout << s.longestPalindrome("abbab");
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string reverseString(string &str)
{
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        int j = i;
        string curr = "";
        while ((str[j] != ' ' && str[j] != '\n') && j < str.length())
        {
            curr += str[j];
            j++;
        };
        if (curr != "")
        {
            if (ans == "")
            {
                ans = curr;
            }
            else
            {
                ans = curr + " " + ans;
            }
        }
        i = j;
    }
    return ans;
}
string ReverseString(string str)
{
    vector<string> v;
    for (int i = 0; i < str.length(); i++)
    {
        int j = i;
        string curr = "";
        while ((str[j] != ' ' && str[j] != '\n') && j < str.length())
        {
            curr += str[j];
            j++;
        };
        if (curr != "")
        {
            v.push_back(curr);
        }
        i = j;
    }
    string ans;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans += v[i];
        if (i != 0)
        {
            ans += " ";
        }
    }
    return ans;
}
int main()
{
    // cout << reverseString("star").size() << endl;
    // cout << reverseString("star");

    return 0;
}
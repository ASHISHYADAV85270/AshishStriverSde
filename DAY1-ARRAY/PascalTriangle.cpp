#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// type 1 -> if r and c is given find the element at that place
/*its answer is simple do   (r-1)C(c-1)
TC->o(r)
SC->o(1)
 */
long long int FindNCR(int n, int r)
{
    long long int res = 1;
    for (long long int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// type 2 -> print the entire row of a given row number n
/*
nth row will have n elements
tc->O(n)
sc->O(1)
*/
vector<int> generateRow(int n)
{
    long long int res = 1;
    vector<int> v;
    v.push_back(res);
    for (long long int i = 1; i < n; i++)
    {
        res = res * (n - i);
        res = res / (i);
        v.push_back(res);
    }
    return v;
}

// type 3 -> print full pascal triangle

void generatePascal(int n)
{
    vector<vector<int>> pas;
    for (int i = 1; i <= n; i++)
    {
        pas.push_back(generateRow(i));
    }
    for (int i = 0; i < pas.size(); i++)
    {
        for (int j = 0; j < pas[i].size(); j++)
        {
            cout << pas[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    generatePascal(6);
    return 0;
}
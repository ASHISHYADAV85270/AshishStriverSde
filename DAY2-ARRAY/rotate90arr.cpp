#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.youtube.com/watch?v=Z0R2u6gd3GU

// with extra space
/*
void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<vector<int>> temp(n, (vector<int>(n)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j][n - i - 1] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = temp[i][j];
        }
    }
}

*/
// without extra space
void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main()
{
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool col_zero = false;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        col_zero = true;
                    }
                }
            }
        }
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (col_zero == true)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
int main()
{
    return 0;
}
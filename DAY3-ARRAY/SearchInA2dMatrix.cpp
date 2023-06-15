#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool searchMatrixPart1(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0, high = rows * cols - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int currele = matrix[mid / cols][mid % cols]; // most important point

            if (target == currele)
            {
                return 1;
            }
            else if (target > currele)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        };

        return 0;
    }

    // type2
    bool searchMatrixPart2(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int curr_row = 0, curr_col = cols - 1; // start from top right
        while (curr_row < rows && curr_col >= 0)
        {
            int element = matrix[curr_row][curr_col];
            if (element == target)
            {
                return 1;
            }
            else if (element < target)
            {
                curr_row++;
            }
            else
            {
                curr_col--;
            }
        };
        return 0;
    }
};
int main()
{
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int ct = 0;
void mergeSort(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] > arr[right])
        {
            temp.push_back(arr[right]);
            ct = ct + mid - left + 1;
            right++;
        }
        else
        {

            temp.push_back(arr[left]);
            left++;
        }
    };

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    };

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    };

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void breakIntoPieces(vector<int> &arr, int low, int high)
{
    if (low == high)
    {
        return;
    }

    int mid = (low + high) / 2;
    breakIntoPieces(arr, low, mid);
    breakIntoPieces(arr, mid + 1, high);

    mergeSort(arr, low, mid, high);
}
int main()
{

    vector<int> arr = {4, 1, 4, 2, 6, 9, 0, -1};
    // 4 + 2 + 3 + 2 + 2 +2 +1 =16
    breakIntoPieces(arr, 0, arr.size() - 1);
    for (auto &val : arr)
    {
        cout << val << " ";
    }
    cout << "\n"
         << ct;
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// tc->2nlogn + 2n
// striver
// sc->o(1)
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 0, j = 0;
    int platform = 0;
    int maxplatform = 0;
    while (j < n && i < n)
    {
        if (arr[i] <= dep[j])
        {
            platform++;
            i++;
            maxplatform = max(maxplatform, platform);
        }
        else
        {
            platform--;
            j++;
        }
    };
    return maxplatform;
}
int main()
{
    return 0;
}
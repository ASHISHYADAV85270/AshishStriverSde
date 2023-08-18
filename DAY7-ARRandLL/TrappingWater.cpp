#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    //tc->n+n+n sc->2n
    int trap(vector<int>& height)
    {
        int n=height.size();
        vector<int> prefix(n),suffix(n);
        prefix[0]=height[0];
        for (int i = 1; i < height.size(); i++)
        {
            prefix[i]=max(prefix[i-1],height[i]);
        }
        suffix[n-1]=height[n-1];
        for (int i =n-2; i >=0; i--)
        {
         suffix[i]=max(suffix[i+1],height[i]);   
        }

        int ans=0;
        for (int i = 0; i < n; i++)
        {
         ans=ans+ min(prefix[i],suffix[i])-height[i];       
        }
        
        return ans;
    }


    //tc->n sc->O(1)
    int trap(vector<int> &height)
    {
        int left=0,right=height.size()-1;
        int left_max=0,right_max=0;
        int ans=0;
        while (left<=right)
        {
            // insuring that every thing on right is greater then left
          if (height[left]<=height[right])
          {
            
                if (height[left]>=left_max)
                {
                    left_max=height[left];
                }
                else
                {
                    ans=ans+left_max-height[left];
                }
                left++;
          }
          else
          {
             if (height[right]>=right_max)
                {
                    right_max=height[right];
                }
                else
                {
                    ans=ans+right_max-height[right];
                }
                right--;
          }
            

        };

        return ans;
        
    }
};
int main()
{
return 0;
}
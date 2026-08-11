#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            // Brute-Force
            // int n=nums.size();
            // vector<int> ans(n,1);
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < n; j++)
            //     {
            //         if(i!=j)
            //             ans[i]*=nums[j];
            //     }  
            // }
            // return ans;

            // Optimal
            int n=nums.size();
            vector<int> prefix(n,1);
            vector<int> suffix(n,1);
            vector<int> ans(n,1);

            for (int i = 1; i < n; i++)
            {
                prefix[i]=prefix[i-1]*nums[i-1];
            }

            for (int i = n-2; i >= 0; i--)
            {
                suffix[i]=suffix[i+1]*nums[i+1];
            }
            
            for (int i = 0; i < n; i++)
            {
                ans[i]=prefix[i]*suffix[i];
            }
            return ans;
        }
};

int main()
{
    vector<int> arr={1,2,3,4,5};
    Solution s;
    
    return 0;
}
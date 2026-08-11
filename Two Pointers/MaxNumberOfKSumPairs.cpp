#include<iostream>
#include<hashtable.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution
{
    public:
        int maxOpertaions(vector<int> &nums, int k)
        {
            sort(nums.begin(),nums.end());
            int len=nums.size();
            int l=0,r=len-1;
            int opertaions=0;
            while(l<r)
            {
                if(nums[l]+nums[r]==k)
                {
                    opertaions++;
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]>k)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
            
            return opertaions;
        }
};


int main()
{
    vector<int> nums={3,1,3,4,3};
    int k=6;
    Solution s;
    cout<<s.maxOpertaions(nums,k)<<endl;
}
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int longestOnes(vector<int>& nums)
    {
        int l=0,maxOnes=0,numZeroes=0;
        int len=nums.size();
        for (int r = 0; r < len; r++)
        {
            if(nums[r]==0)
            {
                numZeroes++;
            }
            while(numZeroes>1)
            {
                if(nums[l]==0)
                {
                    numZeroes--;
                }
                l++;
            }
            int w= r-l;
            maxOnes=max(maxOnes,w);
        }
        return maxOnes;
    }  
};

int main()
{
    vector<int> nums={0,1,1,1,0,1,1,0,1};
    Solution s;
    cout<<s.longestOnes(nums)<<endl;;
    return 0;
}
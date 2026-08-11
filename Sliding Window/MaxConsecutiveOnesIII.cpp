#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int maxOnes(vector<int> &nums, int k)
        {
            int max_w=INT_MIN;
            int numZeroes=0,l=0;
            
            for (int r = 0, len=nums.size(); r < len; r++)
            {
                if(nums[r]==0)
                {
                    numZeroes++;
                }
                while(numZeroes>k)
                {
                    if(nums[l]==0)
                    {
                        numZeroes--;
                    }
                    l++;
                }
                max_w=max(max_w,r-l+1);
            }
            return max_w;
        }
};

int main()
{
    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;

    Solution s;
    cout<<s.maxOnes(nums,k)<<endl;
    return 0;
}
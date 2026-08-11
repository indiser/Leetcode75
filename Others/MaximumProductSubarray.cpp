#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// Leetcode-152:Maximum Product Subarray
class Solution
{
    public:
        int maximumProductSubarray(vector<int> &nums)
        {
            int len=nums.size();
            int maxProd=INT_MIN,prefix=1,suffix=1,currProd=1;;
            for(int i = 0; i < len; i++)
            {
                if(prefix==0)
                    prefix=1;
                if(suffix==0)
                    suffix=1;
                prefix*=nums[i];
                suffix*=nums[len-1-i];
                maxProd=max(maxProd,max(prefix,suffix));
            }
            return maxProd;
        }
};

int main()
{
    vector<int> vec={2,-5,-2,-4,3};
    Solution s;
    cout<<"Maximum product of Subarray is: "<<s.maximumProductSubarray(vec)<<endl;
    return 0;
}
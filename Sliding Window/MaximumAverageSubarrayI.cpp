#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution
{
    public:
        double maxAverage(vector<int>&nums,int k)
        {
            int len=nums.size();
            double maxAvg=INT_MIN;
            double currSum=0;

            //Createing the window
            for (int i = 0; i < k; i++)
            {
                currSum+=nums[i];
            }
            maxAvg=currSum/k;
            
            //Moving along the window
            for (int i = k; i < len; i++)
            {
                currSum+=nums[i];
                currSum-=nums[i-k];
                double avg=currSum/k;
                maxAvg=max(avg,maxAvg);
            }
            return maxAvg;
        }
};

int main()
{
    vector<int> nums={1,12,-5,-6,50,3};
    int k=4;

    Solution s;
    cout<<s.maxAverage(nums,k)<<endl;
    return 0;
}
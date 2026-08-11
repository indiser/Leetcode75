#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        // int len = nums.size();
        // bool b = false;
        // for (int i = 0; i < len; i++)
        // {
        //     for (int j =  i+1; j < len; j++)
        //     {
        //         if(nums[i]<nums[j])
        //         {
        //             for (int k = j+1; k < len; k++)
        //             {
        //                 if(nums[j]<nums[k])
        //                 {
        //                     b=true;
        //                 }
        //             }
                    
        //         }
        //     }
        // }
        // if(b==true){
        //     cout<<"There exists a possibilty where i < j < k"<<endl;
        //     return true;
        // }
        // else
        // {
        //     cout<<"There doenst exist a possibilty where i < j < k"<<endl;
        //     return false;
        // }
        // Time Complexity:O(n*n*n)

        int first=INT_MAX,second=INT_MAX;
        for(int val: nums)
        {
            if(val<=first)
            {
                first=val;
            }
            else if(val<=second)
            {
                second=val;
            }
            else
            {
                return true;
            }
        }
        return false;
        // Time Complexity:O(n)
    }
};

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    Solution s;
    cout<<s.increasingTriplet(vec)<<endl;
}
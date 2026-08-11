#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Approach-1:(Sub Space Optimal)
// class Solution
// {
//     public:
//         vector<int> moveZeroes(vector<int> &nums)
//         {
//             int len=nums.size();
//             int numZero=0;

//             for (int i = 0; i < len; i++)
//             {
//                 if(nums[i]==0)
//                     numZero++;
//             }
//             vector<int> ans;
//             for (int i = 0; i < len; i++)
//             {
//                 if(nums[i]!=0)
//                     ans.push_back(nums[i]);
//             }
//             while(numZero--)
//                 ans.push_back(0);
//             for (int i = 0; i < len; i++)
//             {
//                 nums[i]=ans[i];
//             }
//             return nums;
//         }
// };

// Approach-2:(Space optimal, Operation sub-optimal)

// class Solution
// {
// public:
//     vector<int> moveZeroes(vector<int> &nums)
//     {
//         int n = nums.size();
//         int lastNonZeroFound = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] != 0)
//             {
//                 nums[lastNonZeroFound] = nums[i];
//                 lastNonZeroFound++;
//             }
//         }
//         while (lastNonZeroFound < n)
//         {
//             nums[lastNonZeroFound] = 0;
//             lastNonZeroFound++;
//         }
//         return nums;
//     }
// };

// Approach-3:Optimal
class Solution
{
public:
    vector<int> moveZeroes(vector<int> nums)
    {
        int n = nums.size();
        int lastZeroFoundAt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[lastZeroFoundAt], nums[i]);
                lastZeroFoundAt++;
            }
        }
        return nums;
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 2, 3};
    int n = nums.size();

    Solution s;
    for(int val: s.moveZeroes(nums))
    {
        cout<<val<<endl;
    }

    return 0;
}
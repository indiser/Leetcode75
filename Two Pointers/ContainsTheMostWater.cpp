#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Approach-1:Brute-Force Appraoch
// class Solution
// {
// public:
//     int mostWater(vector<int> &height)
//     {
//         int maxWater = INT_MIN;
//         int len = height.size();

//         for (int i = 0; i < len; i++)
//         {
//             for (int j = i + 1; j < len; j++)
//             {
//                 int w = j - i;
//                 int h = min(height[i], height[j]);
//                 int curWater = w * h;
//                 maxWater = max(maxWater, curWater);
//             }
//         }
//         return maxWater;
//     }
// };

class Solution
{
public:
    int mostWater(vector<int> &height)
    {
        int len=height.size();
        int maxWater=INT_MIN;
        int left=0;
        int right=len-1;
        while(left<right)
        {
            int w=right-left;
            int h=min(height[left],height[right]);
            int currWater=w*h;
            maxWater=max(maxWater,currWater);
            (height[left]<height[right]) ? left++ : right--;
        }
        return maxWater;
    }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution s;
    cout<<s.mostWater(height)<<endl;
    return 0;
}
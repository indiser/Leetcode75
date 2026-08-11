#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

class Solution
{
    public:
        vector<int> getElementsOnlyInFirstList(vector<int> &nums1, vector<int> &nums2)
        {
            set<int> onlyInNums1;
            set<int> existsInNums2;

            for(int num:nums2)
            {
                existsInNums2.insert(num);
            }

            for(int num:nums1)
            {
                if(existsInNums2.find(num)==existsInNums2.end())
                {
                    onlyInNums1.insert(num);
                }
            }
            
            return vector<int>(onlyInNums1.begin(), onlyInNums1.end());
        }

        vector<vector<int>> finDifference(vector<int> &nums1,vector<int> &nums2)
        {
            return {getElementsOnlyInFirstList(nums1,nums2),getElementsOnlyInFirstList(nums2,nums1)};
        }
};

int main()
{
    vector<vector<int>> answer(2);
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4,6};

    Solution s;
    answer=s.finDifference(nums1,nums2);
    for(int val:answer[0])
    {
        cout<<val<<endl;
    }
    for(int val:answer[1])
    {
        cout<<val<<endl;
    }
    return 0;

    
}
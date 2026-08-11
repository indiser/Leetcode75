// Date: 11/08/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

// Time Complexity: O(klogn)
// Space Complexity: O(n)
class Solution
{
    public:
        int findKthLargest(vector<int> &nums, int k)
        {
            priority_queue<int> pq;

            for(int val: nums) pq.push(val);

            int smallest = -1;

            while(k != 0)
            {
                smallest = pq.top();
                pq.pop();
                k--;
            }

            return smallest;
        }
};

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    // vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 4;

    Solution s;
    cout << s.findKthLargest(nums, k) <<endl;

    return 0;
}
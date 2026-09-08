// Date: 08/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        vector<int> countingBits(int n)
        {
            vector<int> dp(n + 1);

            for (int i = 1; i <= n; i++)
            {
                dp[i] = dp[i >> 1] + (i & 1);
            }
            
            return dp;
        }
};

int main()
{
    int n = 5;

    Solution s;
    vector<int> ans = s.countingBits(n);

    for(int val: ans) cout << val << endl;
    return 0;
}
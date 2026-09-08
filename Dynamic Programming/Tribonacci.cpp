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
        int tribonacci(int n)
        {
            if (n <= 0) return 0;
            if (n == 1 || n == 2) return 1;
            vector<int> dp(n + 1);

            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;

            for (int i = 3; i <= n; i++)
            {
                dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1]; 
            }

            return dp[n];
        }
};

int main()
{
    int n = 4;

    Solution s;
    cout<< s.tribonacci(n)<<endl;

    return 0;
}
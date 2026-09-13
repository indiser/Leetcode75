// Date: 13/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
    public:
        vector<int> dailyTemparature(vector<int> &temparatures)
        {
            vector<int> answer(temparatures.size());
            stack<int> st;

            for (int i = 0 , len = temparatures.size(); i < len; i++)
            {
                while(!st.empty() && temparatures[st.top()] < temparatures[i])
                {
                    answer[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
            return answer;
        }
};

int main()
{
    vector<int> temparatures = {73, 74, 75, 71, 69, 72, 76, 73};

    Solution s;
    vector<int> result = s.dailyTemparature(temparatures);

    for(int val: result) cout << val <<endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution
{
public:
    // Time Complexity: O(n) - each senator is processed at most once
    // Space Complexity: O(n) - two queues store all senators
    string dota2Senate(string str)
    {
        queue<int> Radiant;
        queue<int> Dire;
        int len = str.length();

        for (int i = 0; i < len; i++)
        {
            if (str[i] == 'R')
            {
                Radiant.push(i);
            }
            else
            {
                Dire.push(i);
            }
        }
        
        while (!Radiant.empty() && !Dire.empty())
        {
            int r = Radiant.front();
            int d = Dire.front();
            Radiant.pop();
            Dire.pop();
            
            if (r < d)
            {
                Radiant.push(r + len);
            }
            else
            {
                Dire.push(d + len);
            }
        }
        
        return Radiant.empty() ? "Dire" : "Radiant";
    }
};

int main()
{
    string str = "RDD";
    Solution s;
    cout << s.dota2Senate(str) << endl;
    return 0;
}
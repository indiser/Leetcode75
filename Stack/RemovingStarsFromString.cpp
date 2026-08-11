#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

class Solution
{
    public:
    string removeStars(string s)
    {
        string ans="";
        
        for (int i = 0,len = s.size(); i < len; i++)
        {
            if(s[i]=='*')
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

int main()
{
    string str="leet**cod*e";
    Solution s;
    cout<<s.removeStars(str)<<endl;
}
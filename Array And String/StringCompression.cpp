#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

class Solution
{
    public:
        int lengthOfString(vector<char>& chars)
        {
            int index=0;
            int len=chars.size();
            for (int i = 0; i < len; i++)
            {
                char ch=chars[i];
                int count=0;
                while(i<len && chars[i]==ch)
                {
                    count++;
                    i++;
                }
                if(count==1)
                {
                    chars[index++]=ch;
                }
                else
                {
                    chars[index++]=ch;
                    string s=to_string(count);
                    for(int val: s)
                        chars[index++]=val;
                }
                i--;
            }
            chars.resize(index);
            return index;
        }
};

int main()
{
    vector<char> chars={'a','a','b','b','b','b','b','b','b','b','b','b','b','b'};
    Solution s;
    cout<<s.lengthOfString(chars)<<endl;
    for(char val: chars)
    {
        cout<<val<<endl;
    }
    return 0;
}
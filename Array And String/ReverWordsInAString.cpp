#include<iostream>
#include<cctype>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        string reverseWord(string str)
        {
            int len=str.length();
            string ans="";

            reverse(str.begin(),str.end());

            for (int i = 0; i < len; i++)
            {
                string word="";
                while(i<len && str[i]!=' ')
                {
                    word+=str[i];
                    i++;
                }
                

                reverse(word.begin(),word.end());

                if(word.length()>0)
                {
                    ans+=" "+word;
                }
            }
            return ans.substr(1);
            
        }

};

int main()
{ 
    string str=" I am  God ";
    Solution s; 
    cout<<"The string is: "<<s.reverseWord(str)<<endl;
    return 0;
}
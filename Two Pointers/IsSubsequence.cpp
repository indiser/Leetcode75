#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i=0,j=0;
        int slen=s.length(),tlen=t.length();
        while(i<slen && j<tlen)
        {
            if(s[i]==t[j])
                i++;
            j++;
        }
        return i==s.length();
    }
};

int main()
{
    string s = "acb";
    string t = "ahbgdc";

    Solution sub;
    cout<<sub.isSubsequence(s,t)<<endl;
    return 0;
}
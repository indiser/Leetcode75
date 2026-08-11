#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int len = s.size();
        int v = 0, maxVowel = 0;

        for (int i = 0; i < k; i++)
        {
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                v++;
        }
        maxVowel = v;

        for (int i = k; i < len; i++)
        {
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                v++;
            if (s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')
                v--;
            maxVowel = max(maxVowel, v);
        }
        return maxVowel;
    }
};

int main()
{
    string s = "abciiidef";
    int k = 3;
    
    Solution sl;
    cout<<sl.maxVowels(s,k)<<endl;
    return 0;
}
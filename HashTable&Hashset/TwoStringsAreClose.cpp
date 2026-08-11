#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // method-1
        if (word1.size() != word2.size())
            return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        set<char> set1, set2;

        for (char c : word1)
        {
            freq1[c - 'a']++;
            set1.insert(c);
        }

        for (char c : word2)
        {
            freq2[c - 'a']++;
            set2.insert(c);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2 && set1 == set2;

        // method-2
    //     if (word1.length() != word2.length())
    //         return false;

    //     set<char> s1(word1.begin(), word1.end());
    //     set<char> s2(word2.begin(), word2.end());
    //     map<char, int> mp1;
    //     map<char, int> mp2;

    //     for (auto c : word1)
    //         mp1[c++];
    //     for (auto c : word2)
    //         mp2[c++];

    //     if (s1 != s2)
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         for (auto it1 = mp1.begin(), it2 = mp2.begin(); it1 != mp1.end(), it2 != mp2.end(); it1++, it2++)
    //         {
    //             if (it1->second != it2->second)
    //                 it1->second = it2->second;
    //             if (it1->first == it2->first && it1->second == it2->second)
    //                 return true;
    //         }
    //     }
    //     return false;
    }
};

int main()
{
    string word1 = "cabbba";
    string word2 = "aabbss";

    Solution s;
    cout<<s.closeStrings(word1,word2)<<endl;

    return 0;
}
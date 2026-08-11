#include<iostream>
using namespace std;

class Solution
{
    public:
        string Merge(string word1, string word2)
        {
            int m=word1.length();
            int n=word2.length();
            string result="";
            int i=0,j=0;
            while(i<m || j<n)
            {
                if(i<m)
                {
                    result.push_back(word1[i++]);
                }
                if(j<n)
                {
                    result.push_back(word2[j++]);
                }
            }
            return result;
        }
};

int main()
{
    string word1="abc";
    string word2="pqr";
    Solution s;
    cout<<"The result String is: "<<s.Merge(word1,word2)<<endl;
    return 0;
}
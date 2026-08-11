#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {

    private:
        int getGCD(int a,int b)
        {
            return b == 0 ? a : getGCD(b, a % b);
        }

    public:
        string gcdOfStrings(string str1, string str2) 
        {
            int len1 = str1.length(), len2 = str2.length();

            if (len1 == 0) return str2;
            if (len2 == 0) return str1;

            if (str1 + str2 != str2 + str1) return "";

            int gcdLength=getGCD(len1,len2);

            return str1.substr(0,gcdLength);
        }
};

int main()
{
    string s1 = "ABCABC", s2 = "ABC";

    Solution s;

    cout << "The Greatest Common Divisor is: " << s.gcdOfStrings(s1,s2) << endl;
}

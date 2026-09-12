// Date: 12/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<bitset>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
    public:
        int minFlips(int a, int b, int c)
        {
            bitset<32> bitA(a);
            bitset<32> bitB(b);
            bitset<32> bitC(c);

            int count = 0;

            for (int i = 0; i < 32; i++)
            {
                if((bitA[i] | bitB[i]) != bitC[i])
                {
                    if(bitC[i] == 0)
                    {
                        count += bitA[i] + bitB[i];
                    }
                    else count += 1;
                }
            }
            return count;
        }
};

int main()
{
    int a = 2, b = 6, c = 5;

    Solution s;
    cout << s.minFlips(a, b, c) <<endl;
    return 0;
}
// Date: 13/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Brute-Force
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// class Solution
// {
//     public:
//         vector<int> successFulPairs(vector<int> &spells, vector<int> &potions, long long success)
//         {
//             vector<int> result;
            
//             for (int i = 0; i < spells.size(); i++)
//             {
//                 int count = 0;

//                 for (int j = 0; j < potions.size(); j++)
//                 {
//                     if((spells[i] * potions[j]) >= success)
//                     {
//                         count++;
//                     }
//                 }
//                 result.push_back(count);
//             }
//             return result;
//         }
// };

// Optimized Solution: O(nlogn)
// Space Compelxity: O(n)
class Solution
{
    public:
        vector<int> successFulPairs(vector<int> &spells, vector<int> &potions, long long success)
        {
            vector<int> result;
            sort(potions.begin(), potions.end());
            for (int i = 0; i < spells.size(); i++)
            {
                long long start = 0;
                long long end = potions.size() - 1;
                long long valid_index = potions.size();

                while (start <= end)
                {
                    long long mid = start + (end - start) / 2;

                    long long mul = (long long)spells[i] * potions[mid];

                    if(mul >= success)
                    {
                        valid_index = mid;
                        end = mid - 1;
                    }
                    else
                    {
                        start = mid + 1;
                    }
                }
                result.push_back(potions.size() - valid_index);
            }
            return result;
        }
};

int main()
{
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    Solution s;
    vector<int> result = s.successFulPairs(spells, potions, success);

    for(int val: result) cout << val << endl;

    return 0;
}
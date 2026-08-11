#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Time Complexity:O(n^3)
// Space Complexity:O(1)
// class Solution
// {
//     public:
//         int numOfPairs(vector<vector<int>> &grid)
//         {
//             int n=grid.size();
//             int count=0;

//             for (int row = 0; row < n; row++)
//             {
//                 for (int col = 0; col < n; col++)
//                 {
//                     bool match=true;
//                     for (int i = 0; i < n; i++)
//                     {
//                         if(grid[row][i] != grid[i][col])
//                         {
//                             match= false;
//                             break;
//                         }
//                     }
                    
//                     if(match)
//                     {
//                         count++;
//                     }
//                 }
                
//             }
//             return count;
            
//         }
// };

// Time Complexity:O(n^2)
// Space Complexity:O(n^2)

class Solution
{
    public:
        int numOfPairs(vector<vector<int>> &grid)
        {
            int n=grid.size();
            int count=0;

            map<vector<int>,int> count_row;

            for(const auto& row:grid)
            {
                count_row[row]++;
            }

            for (int row = 0; row < n; row++)
            {
                vector<int> current_col;
                for (int col = 0; col < n; col++)
                {
                    current_col.push_back(grid[col][row]);
                }
                if(count_row.count(current_col))
                {
                    count+=count_row[current_col];
                }
            }
            
            return count;
        }
};

int main()
{
    vector<vector<int>> grid={
        {3,2,1},
        {1,7,6},
        {2,7,7}
    };
    Solution s;
    cout<<s.numOfPairs(grid)<<endl;
    return 0;

}
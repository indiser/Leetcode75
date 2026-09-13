// Date: 13/09/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution
{
    public:
        int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
        {
            int m = maze.size();
            int n = maze[0].size();
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));

            int startRow = entrance[0];
            int startCol = entrance[1];

            q.push({startRow, startCol});
            visited[startRow][startCol] = true;

            int rows[]={-1, 1, 0, 0};
            int cols[]={0, 0, -1, 1};

            int steps = 0;

            while(!q.empty())
            {
                int size = q.size();

                for (int i = 0; i < size; i++)
                {
                    auto quads = q.front();
                    q.pop();

                    for (int j = 0; j < 4; j++)
                    {
                        int newRow = rows[j] + quads.first;
                        int newCol = cols[j] + quads.second;
    
                        if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && maze[newRow][newCol] == '.' && !visited[newRow][newCol])
                        {
                            if(newRow == 0 || newRow == m - 1 || newCol == 0 || newCol == n -1) return steps + 1;
                            q.push({newRow, newCol});
                            visited[newRow][newCol] = true;
                        }
                    }
                }
                steps++;
            }

            return -1;
        }
};

int main()
{
    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}
    };

    vector<int> entrance = {1, 2};

    Solution s;
    cout << s.nearestExit(maze, entrance)<< endl;
    return 0;
}
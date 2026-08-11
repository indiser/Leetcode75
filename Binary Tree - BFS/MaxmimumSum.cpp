#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>
#include<functional>
#include<climits>
using namespace std;

// Time Complexity: O(n) - visit each node once
// Space Complexity: O(h + L) - recursion stack + level sums storage


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:
        void helper(TreeNode *node, int level, vector<long long> &ans)
        {
            if(!node) return;
            if(level==ans.size())
            {
                ans.push_back(node->val);
            }
            else
            {
                ans[level]+=node->val;
            }
            helper(node->left,level+1,ans);
            helper(node->right,level+1,ans);
        }
        // Time: O(n), Space: O(h + L)
        int maxLevelSum(TreeNode *root)
        {
            vector<long long> ans;
            helper(root,0,ans);
            long long maxSum=INT_MIN;
            int index=0;
            for (int i = 0; i < ans.size(); i++)
            {
                if(ans[i]>maxSum)
                {
                    maxSum=ans[i];
                    index=i+1;
                }
            }
            return index;
        }
        
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    
    Solution s;
    cout<<s.maxLevelSum(root)<<endl;
    
    return 0;
}
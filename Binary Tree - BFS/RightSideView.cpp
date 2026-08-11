#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>
#include<functional>
using namespace std;

// Time Complexity: O(n) - visit each node once
// Space Complexity: O(h) - recursion stack depth


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
        void view(TreeNode *node, vector<int> &ans, int level)
        {
            if(!node) return;
            if(level==ans.size()) ans.push_back(node->val);
            view(node->right,ans,level+1);
            view(node->left,ans,level+1);
        }
        // Time: O(n), Space: O(h)
        vector<int> rightSideView(TreeNode *root)
        {
            vector<int> ans;
            view(root,ans,0);
            return ans;
        }
        
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    
    Solution s;
    vector<int> ans = s.rightSideView(root);

    for(int val:ans)
    {
        cout<<val<<endl;
    }
    
    return 0;
}
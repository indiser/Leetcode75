#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n²) - for each node, explore all paths downward
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
        
        int findSum(TreeNode *root, long long targetSum)
        {
            if(root==nullptr)
            {
                return 0;
            }
            int count=0;
            targetSum-=root->val;
            if(targetSum==0)
            {
                count=1;
            }
            count+=findSum(root->left,targetSum);
            count+=findSum(root->right,targetSum);
            return count;
        }
        // Time: O(n²), Space: O(h)
        int pathSum(TreeNode *root, int targetSum)
        {
            if(!root) return 0;
            return findSum(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
        }
};

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    int targetSum=8;
    Solution s;
    cout << s.pathSum(root,targetSum) << endl;
    return 0;
}
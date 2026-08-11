#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
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
        void inOrderTraverse(TreeNode *root)
        {
            if (root == nullptr)
                return;
            inOrderTraverse(root->left);
            cout << root->val << " ";
            inOrderTraverse(root->right);
        }
        int countGoodNodes(TreeNode *root, int max_so_far)
        {
            if(!root)
            {
                return 0;
            }
            int count=0;
            if(root->val>=max_so_far)
            {
                count++;
            }
            int new_max=max(root->val,max_so_far);
            count+=countGoodNodes(root->left, new_max);
            count+=countGoodNodes(root->right, new_max);
            return count;
        }
        // Time: O(n), Space: O(h)
        int goodNodes(TreeNode *root)
        {
            return countGoodNodes(root, INT_MIN);
        }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    
    Solution s;
    cout << s.goodNodes(root) << endl;
    return 0;
}
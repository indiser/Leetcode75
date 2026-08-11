#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity: O(n) - visit each node once
// Space Complexity: O(h) - recursion stack depth, where h is height of tree

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
        // Time: O(n), Space: O(h)
        int maxDepth(TreeNode *root)
        {
            if(root == NULL)
            {
                return 0;
            }
            int leftCount = maxDepth(root->left);
            int rightCount = maxDepth(root->right);
            return 1 + max(leftCount, rightCount);
        }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    Solution s;
    s.inOrderTraverse(root);
    cout<<endl;
    cout<<s.maxDepth(root)<<endl;
    return 0;
}

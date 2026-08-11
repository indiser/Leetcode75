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
        int maxLength=0;
        void maxZigZag(TreeNode *node, bool isLeft, int length)
        {
            if(!node) return;
            maxLength=max(maxLength,length);

            if(isLeft)
            {
                maxZigZag(node->right,false,length+1);
                maxZigZag(node->left,true,1);
            }
            else
            {
                maxZigZag(node->left,true,length+1);
                maxZigZag(node->right,false,1);
            }

        }
        // Time: O(n), Space: O(h)
        int longestZigZag(TreeNode *root)
        {
            if(!root) return 0;

            maxZigZag(root->left,true,1);
            maxZigZag(root->right,false,1);
            return maxLength;
        }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->right->right = new TreeNode(1);
    root->right->right->left->right = new TreeNode(1);
    root->right->right->left->left = new TreeNode(1);
    
    Solution s;
    cout << s.longestZigZag(root) << endl;
    return 0;
}
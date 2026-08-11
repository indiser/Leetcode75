#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>
#include<functional>
#include<climits>
using namespace std;

// Time Complexity: O(h) - height of BST
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
       // Time: O(h), Space: O(h)
       TreeNode *searchBST(TreeNode *root, int val)
       {
           if(!root || root->val == val) return root;
           return (val < root->val) ? searchBST(root->left, val) : searchBST(root->right, val);
       }
        
};

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    Solution s;
    TreeNode* result = s.searchBST(root, val);
    
    if(result) {
        cout << result->val << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    return 0;
}
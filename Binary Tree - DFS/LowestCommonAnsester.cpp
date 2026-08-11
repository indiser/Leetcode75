#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>
#include<functional>
using namespace std;



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
        TreeNode *lowestCommonAnsester(TreeNode *root, TreeNode *p, TreeNode *q)
        {
            if(!root) return NULL;

            if(root == p || root ==q) return root;

            TreeNode *left_result=lowestCommonAnsester(root->left,p,q);
            TreeNode *right_result=lowestCommonAnsester(root->right,p,q);

            if(left_result != nullptr && right_result != nullptr) return root;

            return (left_result != nullptr) ? left_result : right_result;
        }
        
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    TreeNode* p = root->left;        // p = 5
    TreeNode* q = root->left->right->right;  // q = 4
    
    Solution s;
    TreeNode* lca = s.lowestCommonAnsester(root, p, q);
    cout << lca->val << endl;
    
    return 0;
}
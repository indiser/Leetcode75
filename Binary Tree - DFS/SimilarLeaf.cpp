#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time Complexity: O(n + m) - visit all nodes in both trees
// Space Complexity: O(h + L) - recursion stack + leaf storage

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
        void getLeaves(TreeNode *root, vector<int>& leaves)
        {
            if(!root) return;
            if(!root->left && !root->right) {
                leaves.push_back(root->val);
                return;
            }
            getLeaves(root->left, leaves);
            getLeaves(root->right, leaves);
        }
        
        // Time: O(n + m), Space: O(h + L)
        bool similarLeaf(TreeNode *root1, TreeNode *root2)
        {
            vector<int> leaves1, leaves2;
            getLeaves(root1, leaves1);
            getLeaves(root2, leaves2);
            return leaves1 == leaves2;
        }
};

int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    
    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    
    Solution s;
    cout << s.similarLeaf(root1, root2) << endl;
    return 0;
}

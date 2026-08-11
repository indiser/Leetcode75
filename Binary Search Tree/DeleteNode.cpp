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
        void inOrderTraversal(TreeNode *root)
        {
            if(root != NULL)
            {
                inOrderTraversal(root->left);
                cout<<root->val<<" ";
                inOrderTraversal(root->right);
            }
        }
        // Time: O(h), Space: O(h)
        TreeNode *deleteNode(TreeNode* root, int key)
        {
            if(!root) return nullptr;
            
            if(key < root->val) {
                root->left = deleteNode(root->left, key);
            }
            else if(key > root->val) {
                root->right = deleteNode(root->right, key);
            }
            else {
                // Node to delete found
                if(!root->left) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
                else if(!root->right) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                else {
                    // Node with two children - find inorder successor
                    TreeNode* temp = root->right;
                    while(temp->left) temp = temp->left;
                    root->val = temp->val;
                    root->right = deleteNode(root->right, temp->val);
                }
            }
            return root;
        }
};

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    
    Solution s;
    cout << "Before deletion: ";
    s.inOrderTraversal(root);
    cout << endl;
    
    int key = 3;
    root = s.deleteNode(root, key);
    
    cout << "After deleting " << key << ": ";
    s.inOrderTraversal(root);
    cout << endl;
    
    return 0;
}
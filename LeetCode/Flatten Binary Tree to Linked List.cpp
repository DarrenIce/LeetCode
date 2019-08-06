/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* getright(TreeNode* root) {
        if (root->right)
            return getright(root->right);
        return root;
    }
    void flatten(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            TreeNode* node=getright(root->left);
            node->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }
        flatten(root->right);
    }
};
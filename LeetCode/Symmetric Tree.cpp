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
    bool dfs(TreeNode* l,TreeNode* r) {
        if (!l&&!r)
            return true;
        else if (l&&r&&l->val==r->val)
            return dfs(l->left,r->right)&&dfs(l->right,r->left);
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return dfs(root->left,root->right);
    }
};
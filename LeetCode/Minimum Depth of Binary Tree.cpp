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
    int dfs(TreeNode* tpr) {
        if (!tpr)
            return 0;
        if (!tpr->left&&!tpr->right)
            return 1;
        int l=INT_MAX;
        if (tpr->left)
            l=dfs(tpr->left);
        int r=INT_MAX;
        if (tpr->right)
            r=dfs(tpr->right);
        return 1+min(l,r);
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};
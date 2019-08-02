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
    bool dfs(TreeNode* tpr,int sum) {
        if (!tpr)
            return false;
        if (!tpr->left&&!tpr->right)
            return sum==tpr->val;
        return dfs(tpr->left,sum-tpr->val)||dfs(tpr->right,sum-tpr->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root,sum);
    }
};
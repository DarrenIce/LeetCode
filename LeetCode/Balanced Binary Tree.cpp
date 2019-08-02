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
    int dfs(TreeNode* tpr,bool& flag) {
        if (!tpr)
            return 0;
        int lh=dfs(tpr->left,flag);
        int rh=dfs(tpr->right,flag);
        int height=1+max(lh,rh);
        if (abs(lh-rh)>1)
            flag=false;
        return height;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        bool flag=true;
        dfs(root,flag);
        return flag;
    }
};
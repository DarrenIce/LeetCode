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
    TreeNode* head;
    bool dfs(TreeNode* tpr,long long lower,long long upper) {
        if (tpr==NULL)
            return true;
        if (tpr->val>lower&&tpr->val<upper)
            return dfs(tpr->left,lower,tpr->val)&&dfs(tpr->right,tpr->val,upper);
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        head=root;
        return dfs(root,INT64_MIN,INT64_MAX);
    }
};
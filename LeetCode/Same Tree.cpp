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
    bool dfs(TreeNode* p,TreeNode* q) {
        if (!p&&!q)
            return true;
        else if (p&&q&&p->val==q->val)
            return dfs(p->left,q->left)&&dfs(p->right,q->right);
        else
            return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};
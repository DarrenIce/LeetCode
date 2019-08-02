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
    void dfs(TreeNode* p,int k,int& depth) {
        if (!p)
            depth=max(k,depth);
        else {
            dfs(p->left,k+1,depth);
            dfs(p->right,k+1,depth);
        }
    }
    int maxDepth(TreeNode* root) {
        int depth=0;
        dfs(root,0,depth);
        return depth;
    }
};
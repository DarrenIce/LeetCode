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
    pair<int,int> dfs(TreeNode* root) {
        pair<int,int> l{},r{},cur{};
        if (root->left)
            l=dfs(root->left);
        if (root->right)
            r=dfs(root->right);
        cur.second=max(l.first+r.first,max(l.first+r.second,max(l.second+r.first,l.second+r.second)));
        cur.first=root->val+l.second+r.second;
        return cur;
    }
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        pair<int,int> p=dfs(root);
        return p.first>p.second?p.first:p.second;
    }
};
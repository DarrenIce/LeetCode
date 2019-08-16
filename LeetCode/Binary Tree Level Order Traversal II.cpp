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
    void dfs(vector<TreeNode*> q,vector<vector<int>>& res) {
        vector<TreeNode*> temp;
        vector<int> ans;
        for (int i=0;i<q.size();i++) {
            if (q[i]->left)
                temp.push_back(q[i]->left);
            if (q[i]->right)
                temp.push_back(q[i]->right);
        }
        if (!temp.empty())
            dfs(temp,res);
        for (int i=0;i<q.size();i++) {
            ans.push_back(q[i]->val);
        }
        res.push_back(ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return vector<vector<int>>{};
        vector<vector<int>> res;
        vector<TreeNode*> q;
        q.push_back(root);
        dfs(q,res);
        return res;
    }
};
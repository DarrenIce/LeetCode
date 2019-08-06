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
    void dfs(TreeNode* root,int sum,deque<int>& path,vector<vector<int>>& res) {
        if (!root)
            return;
        if (!root->left&&!root->right&&root->val==sum) {
            path.push_back(root->val);
            vector<int> temp;
            copy(path.begin(),path.end(),back_inserter(temp));
            path.pop_back();
            res.push_back(temp);
            return;
        }
        path.push_back(root->val);
        dfs(root->left,sum-root->val,path,res);
        dfs(root->right,sum-root->val,path,res);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        deque<int> path;
        dfs(root,sum,path,res);
        return res;
    }
};
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
    void dfs(TreeNode* root,string& s,vector<string>& res) {
        if (!root)
            return;
        if (!root->left&&!root->right) {
            string t=to_string(root->val);
            s+=t;
            res.push_back(s);
            s=s.substr(0,s.size()-t.size());
            return;
        }
        string t=to_string(root->val)+"->";
        s+=t;
        dfs(root->left,s,res);
        dfs(root->right,s,res);
        s=s.substr(0,s.size()-t.size());
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> res;
        dfs(root,s,res);
        return res;
    }
};
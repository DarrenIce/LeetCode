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
    void inorder(TreeNode* root,vector<int>& ans) {
        if (!root)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void rec(TreeNode* root,int a,int b) {
        if (root) {
            if (root->val==a)
                root->val=b;
            else if (root->val==b)
                root->val=a;
            rec(root->left,a,b);
            rec(root->right,a,b);
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        vector<int> temp=ans;
        sort(temp.begin(),temp.end());
        int a=-1,b=-1;
        for (int i=0;i<ans.size();i++) {
            if (ans[i]!=temp[i])
                if (a==-1)
                    a=ans[i];
                else
                    b=ans[i];
        }
        rec(root,a,b);
    }
};
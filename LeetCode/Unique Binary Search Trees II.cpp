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
    vector<TreeNode*> bst(int left,int right) {
        vector<TreeNode*> t;
        if (left>right) {
            t.push_back(NULL);
        }
        for (int i=left;i<=right;i++) {
            vector<TreeNode*> l=bst(left,i-1);
            vector<TreeNode*> r=bst(i+1,right);
            for (int j=0;j<l.size();j++) {
                for (int k=0;k<r.size();k++) {
                    TreeNode* cur=new TreeNode(i);
                    cur->left=l[j];
                    cur->right=r[k];
                    t.push_back(cur);
                }
            }
        }
        return t;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n==0)
            return res;
        return bst(1,n);
    }
};
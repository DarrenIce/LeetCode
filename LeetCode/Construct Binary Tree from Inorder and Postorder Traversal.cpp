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
    int pos,in;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pos=in=inorder.size()-1;
        return build(inorder,postorder,INT_MIN);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int stop) {
        if (pos<0)
            return NULL;
        if (inorder[in]==stop)
        {
            in--;
            return NULL;
        }
        TreeNode* tn=new TreeNode(postorder[pos--]);
        tn->right=build(inorder,postorder,tn->val);
        tn->left=build(inorder,postorder,stop);
        return tn;
    }
};
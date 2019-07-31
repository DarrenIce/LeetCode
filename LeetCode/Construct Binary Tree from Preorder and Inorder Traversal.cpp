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
    int z=0;
    int find (vector<int>& inorder, int begin, int end, int item)
    {
        for (int i=begin;i<=end;i++)
        {
            if (inorder[i]==item)
                return i;
        }
        return 0;
    }
    TreeNode* recursion(int begin, int end, vector<int>& preorder, vector<int>& inorder)
    {
        if (begin>end)
            return NULL;
        TreeNode* tn=new TreeNode(preorder[z]);
        int mid=find(inorder,begin,end,tn->val);
        z++;
        tn->left=recursion(begin,mid-1,preorder,inorder);
        tn->right=recursion(mid+1,end,preorder,inorder);
        return tn;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* tn=new TreeNode(0);
        tn=recursion(0,preorder.size()-1,preorder,inorder);
        return tn;
    }
    
};
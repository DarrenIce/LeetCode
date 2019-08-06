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
    int dfs(TreeNode* head,int num) {
        if (!head)
            return 0;
        num=num*10+head->val;
        if (!head->left&&!head->right)
            return num;
        return dfs(head->left,num)+dfs(head->right,num);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};
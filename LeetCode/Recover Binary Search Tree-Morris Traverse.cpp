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
    void recoverTree(TreeNode* root) {
        TreeNode *first=NULL,*second=NULL,*pre=NULL,*father=NULL,*cur=root;
        while (cur) {
            if (!cur->left) {
                if (father&&father->val>cur->val) {
                    if (!first)
                        first=father;
                    second=cur;
                }
                father=cur;
                cur=cur->right;
            }
            else {
                pre=cur->left;
                while (pre->right&&pre->right!=cur)
                    pre=pre->right;
                if (!pre->right) {
                    pre->right=cur;
                    cur=cur->left;
                }
                else {
                    pre->right=NULL;
                    if (father->val>cur->val) {
                        if (!first)
                            first=father;
                        second=cur;
                    }
                    father=cur;
                    cur=cur->right;
                }
            }
        }
        swap(first->val,second->val);
    }
};
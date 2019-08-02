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
    TreeNode* dfs(vector<int>::iterator begin,vector<int>::iterator end) {
        if (begin!=end) {
            int mid=(end-begin)/2;
            TreeNode* tpr=new TreeNode(*(begin+mid));
            tpr->left=dfs(begin,begin+mid);
            tpr->right=dfs(begin+mid+1,end);
            return tpr;
        }
        else
            return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums.begin(),nums.end());
    }
};
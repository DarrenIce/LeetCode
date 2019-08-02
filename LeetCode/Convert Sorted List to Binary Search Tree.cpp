/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int size=0;
        ListNode* cur=head;
        while (cur) {
            size++;
            cur=cur->next;
        }
        cur=head;
        vector<int> nums(size,0);
        for (int i=0;i<size;i++) {
            nums[i]=cur->val;
            cur=cur->next;
        }
        return dfs(nums.begin(),nums.end());
    }
};
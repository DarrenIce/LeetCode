/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur=head;
        while (cur) {
            if (cur->next&&cur->val==cur->next->val)
                cur->next=cur->next->next;
            else
                cur=cur->next;
        }
        return head;
    }
};
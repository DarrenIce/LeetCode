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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return head;
        ListNode* h=new ListNode(0);
        ListNode* cur=head;
        ListNode* pre=h;
        while (cur) {
           while (pre->next&&pre->next->val<=cur->val)
               pre=pre->next;
            ListNode* next=cur->next;
            cur->next=pre->next;
            pre->next=cur;
            cur=next;
            pre=h;
        }
        return h->next;
    }
};
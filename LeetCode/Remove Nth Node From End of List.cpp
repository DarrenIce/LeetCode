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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=new ListNode(0);
        temp->next=head;
        auto cur=temp;
        auto fast=temp;
        for (int i=0;i<=n;i++) {
            fast=fast->next;
        }
        while (fast) {
            cur=cur->next;
            fast=fast->next;
        }
        cur->next=cur->next->next;
        return temp->next;
    }
};
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h=new ListNode(INT_MIN);
        h->next=head;
        ListNode* first=h;
        ListNode* second=h->next;
        while (first) {
            if (first->next&&first->next->val>=x) {
                second=first->next;
                while (second) {
                    if (second->next&&second->next->val<x) {
                        ListNode* temp=second->next;
                        second->next=second->next->next;
                        temp->next=first->next;
                        first->next=temp;
                        first=first->next;
                    }
                    else {
                        second=second->next;
                    }
                }
                first=first->next;
            }
            else {
                first=first->next;
            }
        }
        return h->next;
    }
};
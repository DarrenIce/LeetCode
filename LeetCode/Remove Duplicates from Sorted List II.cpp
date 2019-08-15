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
        ListNode* h=new ListNode(0);
        h->next=head;
        ListNode* first=h;
        ListNode* second=h->next;
        int dep=INT_MAX;
        while (second) {
            if (second->val==dep) {
                first->next=second->next;
                second=first->next;
            }
            else if (second->next&&second->val==second->next->val) {
                dep=second->val;
                first->next=second->next->next;
                second=first->next;
            }
            else {
                dep=second->val;
                first=second;
                second=first->next;
            }
        }
        return h->next;
    }
};
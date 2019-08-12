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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=new ListNode(0);
        temp->next=head;
        auto cur=temp;
        while (cur->next&&cur->next->next) {
            auto t=cur->next;
            cur->next=cur->next->next;
            t->next=cur->next->next;
            cur->next->next=t;
            cur=cur->next->next;
        }
        return temp->next;
    }
};
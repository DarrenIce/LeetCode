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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp1=new ListNode(0);
        ListNode* temp2=new ListNode(0);
        temp1->next=l1;
        temp2->next=l2;
        auto t1=temp1,t2=temp2;
        ListNode* head=new ListNode(0);
        auto cur=head;
        while (t1->next&&t2->next) {
            if (t1->next->val>=t2->next->val) {
                auto temp=t2->next;
                t2->next=t2->next->next;
                cur->next=temp;
                cur=cur->next;
            }
            else {
                auto temp=t1->next;
                t1->next=t1->next->next;
                cur->next=temp;
                cur=cur->next;
            }
        }
        if (t1->next)
            cur->next=t1->next;
        else
            cur->next=t2->next;
        return head->next;
    }
};
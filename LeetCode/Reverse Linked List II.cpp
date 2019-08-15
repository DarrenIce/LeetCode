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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head||!head->next||m==n)
            return head;
        ListNode* h=new ListNode(0);
        h->next=head;
        ListNode* first=h;
        ListNode* second=h;
        for (int i=0;i<m-1;i++)
            first=first->next;
        for (int i=0;i<n;i++)
            second=second->next;
        ListNode* l1=first->next;
        ListNode* l2=l1->next;
        first->next=second;
        second=second->next;
        ListNode* temp=second;
        while (l1!=temp) {
            l1->next=second;
            second=l1;
            l1=l2;
            if (l1)
                l2=l1->next;
        }
        return h->next;
        
    }
};
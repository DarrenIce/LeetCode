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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head||!head->next||k<2)
            return head;
        int count=1;
        auto p=head;
        while (count!=k) {
            p=p->next;
            if (!p)
                return head;
            ++count;
        }
        auto next=p->next;
        p->next=NULL;
        auto l1=head;
        auto l2=head->next;
        l1->next=NULL;
        while (l2) {
            auto temp=l2->next;
            l2->next=l1;
            l1=l2;
            l2=temp;
        }
        head->next=reverseKGroup(next,k);
        return l1;
    }
};
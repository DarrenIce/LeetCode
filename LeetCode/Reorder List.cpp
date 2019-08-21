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
    void reorderList(ListNode* head) {
        if (!head)
            return;
        stack<ListNode*> m;
        ListNode* fast=head;
        ListNode* slow=head;
        while (fast&&fast->next) {
            fast=fast->next->next;
            slow=slow->next;
        }
        while (slow) {
            m.push(slow);
            slow=slow->next;
        }
        slow=head;
        while (!m.empty()) {
            auto t=m.top();
            m.pop();
            t->next=slow->next;
            slow->next=t;
            slow=t->next;
        }
        slow->next=NULL;
    }
};
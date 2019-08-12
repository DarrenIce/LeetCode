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
    struct cmp {
      bool operator ()(ListNode* &a,ListNode* &b) {
          return a->val>b->val;
      }  
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        ListNode* head=new ListNode(0);
        auto cur=head;
        for (auto& l:lists) {
            if (l)
                pq.push(l);
        }
        while (!pq.empty()) {
            auto temp=pq.top();
            pq.pop();
            cur->next=new ListNode(temp->val);
            cur=cur->next;
            if (temp->next)
                pq.push(temp->next);
        }
        return head->next;
    }
};
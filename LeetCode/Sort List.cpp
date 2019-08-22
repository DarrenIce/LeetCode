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
    ListNode* sortList(ListNode* head) {
        if (!head)
            return head;
        ListNode* h=new ListNode(0);
        ListNode* pre=h;
        h->next=head;
        ListNode* cur=head;
        int size=0;
        while (cur) {
            ++size;
            cur=cur->next;
        }
        for (int i=1;i<size;i=i*2) {
            pre=h;
            for (int j=0;j<size;j=j+2*i) {
                ListNode* left=pre->next;
                ListNode* right=pre->next;
                ListNode* temp;
                for (int k=0;k<i&&right;k++)
                    right=right->next;
                for (int x=0,y=0;(x<i&&left)||(y<i&&right);) {
                    if (x<i&&left&&(!right||y>=i||left->val<=right->val)) {
                        pre->next=left;
                        left=left->next;
                        pre=pre->next;
                        x++;
                    }
                    else if (y<i&&right&&(!left||x>=i||left->val>right->val)) {
                        pre->next=right;
                        right=right->next;
                        pre=pre->next;
                        y++;
                    }
                }
                pre->next=right;
            }
        }
        return h->next;
    }
};
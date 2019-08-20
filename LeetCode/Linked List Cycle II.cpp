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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fp=head;
        ListNode* sp=head;
        while (fp&&fp->next) {
            fp=fp->next->next;
            sp=sp->next;
            if (fp==sp)
                break;
        }
        if (!fp||!fp->next)
            return NULL;
        fp=head;
        while(fp!=sp) {
            fp=fp->next;
            sp=sp->next;
        }
        return fp;
    }
};
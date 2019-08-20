/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        unordered_map<int,Node*> m;
        Node* cur=head;
        while (cur) {
            auto it=m.find(cur->val);
            Node* nptr;
            if (it==m.end()) {
                nptr=new Node();
                nptr->val=cur->val;
                m[nptr->val]=nptr;
            }
            else {
                nptr=it->second;
            }
            if (cur->next) {
                it=m.find(cur->next->val);
                Node* nextptr;
                if (it==m.end()) {
                    nextptr=new Node();
                    nextptr->val=cur->next->val;
                    m[nextptr->val]=nextptr;
                }
                else {
                    nextptr=it->second;
                }
                nptr->next=nextptr;
            }
            else {
                nptr->next=NULL;
            }
            if (cur->random) {
                it=m.find(cur->random->val);
                Node* ranptr;
                if (it==m.end()) {
                    ranptr=new Node();
                    ranptr->val=cur->random->val;
                    m[ranptr->val]=ranptr;
                }
                else {
                    ranptr=it->second;
                }
                nptr->random=ranptr;
            }
            else {
                nptr->random=NULL;
            }
            cur=cur->next;
        }
        auto it=m.find(head->val);
        return it->second;
    }
};
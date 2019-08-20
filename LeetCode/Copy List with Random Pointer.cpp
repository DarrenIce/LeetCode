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
        map<Node*,Node*> m;
        Node* cur=head;
        while (cur) {
            Node* nptr=new Node();
            nptr->val=cur->val;
            m[cur]=nptr;
            cur=cur->next;
        }
        cur=head;
        while (cur) {
            Node* n=m[cur];
            n->next=cur->next?m[cur->next]:NULL;
            n->random=cur->random?m[cur->random]:NULL;
            cur=cur->next;
        }
        return m[head];
    }
};
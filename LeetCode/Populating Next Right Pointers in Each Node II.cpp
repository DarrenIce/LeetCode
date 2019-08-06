/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<Node*> v;
            for (int i=q.size();i>0;i--) {
                Node* n=q.front();
                q.pop();
                v.push_back(n);
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
            int i=0;
            for (;i<v.size()-1;i++) {
                v[i]->next=v[i+1];
            }
            v[i]->next=NULL;
        }
        return root;
    }
};
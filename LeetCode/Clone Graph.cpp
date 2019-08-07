/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        map<Node*,Node*> m;
        return dfs(node,m);
    }
    Node* dfs(Node* node,map<Node*,Node*>&m) {
        auto it=m.find(node);
        if (it!=m.end())
            return it->second;
        Node* n=new Node(node->val,node->neighbors);
        m.insert(map<Node*,Node*>::value_type(node,n));
        for (int i=0;i<node->neighbors.size();i++) {
            it=m.find(node->neighbors[i]);
            if (it==m.end())
                n->neighbors[i]=dfs(node->neighbors[i],m);
            else
                n->neighbors[i]=it->second;
        }
        return n;
    }
};
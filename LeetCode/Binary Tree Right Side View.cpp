/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return vector<int> {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int> vi;
        while (!q.empty()) {
            vector<TreeNode*> vt;
            for (int i=q.size();i>0;i--) {
                TreeNode* t=q.front();
                q.pop();
                vt.push_back(t);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            vi.push_back(vt[vt.size()-1]->val);
        }
        return vi;
    }
    
};
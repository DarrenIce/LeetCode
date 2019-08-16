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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return vector<vector<int>>{};
        bool reverse=false;
        deque<TreeNode*> deq;
        vector<vector<int>> res;
        deq.push_back(root);
        while (!deq.empty()) {
            vector<int> ans;
            deque<TreeNode*> temp;
            for (int i=deq.size();i>0;i--) {
                if (reverse) {
                    auto p=deq.back();
                    deq.pop_back();
                    ans.push_back(p->val);
                    if (p->right)
                        temp.push_front(p->right);
                    if (p->left)
                        temp.push_front(p->left);
                }
                else {
                    auto p=deq.front();
                    deq.pop_front();
                    ans.push_back(p->val);
                    if (p->left)
                        temp.push_back(p->left);
                    if (p->right)
                        temp.push_back(p->right);
                }
            }
            reverse=!reverse;
            res.push_back(ans);
            deq=temp;
        }
        return res;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> bst;
    int cur;
    BSTIterator(TreeNode* root) {
        inorder(root);
        cur=0;
    }
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        bst.push_back(root->val);
        inorder(root->right);
    }
    /** @return the next smallest number */
    int next() {
        return bst[cur++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (cur>=bst.size())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
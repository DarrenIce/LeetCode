class Solution {
public:
    vector<vector<int>> res;
    void bt(int n,int k,int start,int left,vector<int>& ans) {
        if (k==ans.size()) {
            res.push_back(ans);
            return;
        } else {
            for (int i=start;i<=n-left+1;i++) {
                ans.push_back(i);
                bt(n,k,i+1,left-1,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if (n==0||k==0||n<k)
            return res;
        vector<int> ans;
        bt(n,k,1,k,ans);
        return res;
    }
};
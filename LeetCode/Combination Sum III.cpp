class Solution {
public:
    void dfs(int k,int n,int i,vector<int>& ans,vector<vector<int>>& res) {
        if (0==k&&0==n) {
            res.push_back(ans);
        }
        else if (k==0||n==0)
            return;
        else {
            for (;i<=9;i++) {
                if (i<=n) {
                    ans.push_back(i);
                    dfs(k-1,n-i,i+1,ans,res);
                    ans.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k==0||n==0||n>45)
            return vector<vector<int>> {};
        vector<vector<int>> res;
        vector<int> ans;
        dfs(k,n,1,ans,res);
        return res;
    }
};
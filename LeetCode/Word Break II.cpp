class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        unordered_map<int,vector<string>> m;
        for (int i=1;i<=s.size();i++) {
            for (auto word:wordDict) {
                bool flag=i>=word.size()?s.substr(i-word.size(),word.size())==word&&dp[i-word.size()]:false;
                dp[i]=dp[i]||flag;
                if (flag)
                    m[i].push_back(word);
            }
        }
        vector<string> res;
        string ans;
        if (dp[s.size()])
            dfs(s.size(),m,ans,res);
        else
            return vector<string>{};
        return res;
    }
    void dfs(int i,unordered_map<int,vector<string>>& m,string &ans,vector<string>& res) {
        if (i==0) {
            ans=ans.substr(1);
            res.push_back(ans);
            ans=" "+ans;
            return;
        }
        for (auto word:m[i]) {
            ans=' '+word+ans;
            dfs(i-word.size(),m,ans,res);
            ans=ans.substr(word.size()+1);
        }
    }
};
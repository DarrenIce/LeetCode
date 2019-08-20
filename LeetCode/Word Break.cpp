class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for (int i=1;i<=s.size();i++) {
            for (auto word:wordDict) {
                dp[i]=dp[i]||(i>=word.size()?(s.substr(i-word.size(),word.size())==word&&dp[i-word.size()]):false);
            }
        }
        return dp[s.size()];
    }
};
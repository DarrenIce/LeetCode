class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for (int i=1;i<=s.size();i++) {
            for (auto word:wordDict) {
                if (i<word.size())
                    dp[i]=dp[i]||false;
                else
                    dp[i]=dp[i]||(s.substr(i-word.size(),word.size())==word&&dp[i-word.size()]);
            }
        }
        return dp[s.size()];
    }
};
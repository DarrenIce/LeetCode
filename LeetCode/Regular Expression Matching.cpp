class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0]=true;
        for (int i=2;i<=p.size();i++) {
            if (p[i-1]=='*')
                dp[0][i]=dp[0][i-2];
        }
        for (int i=1;i<=s.size();i++) {
            for (int j=1;j<=p.size();j++) {
                if (s[i-1]==p[j-1]||p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if (p[j-1]=='*') {
                    dp[i][j]=dp[i][j-2];
                    if (s[i-1]==p[j-2]||p[j-2]=='.')
                        dp[i][j]=dp[i-1][j]||dp[i][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
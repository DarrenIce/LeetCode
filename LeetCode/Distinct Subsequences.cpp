class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long> dp(t.size()+1,0);
        dp[0]=1;
        for (int i=1;i<=s.size();i++) {
            vector<long long> pre=dp;
            for (int j=1;j<=t.size();j++) {
                dp[j]=pre[j]+(t[j-1]==s[i-1]?pre[j-1]:0);
            }
        }
        return dp[t.size()];
    }
};
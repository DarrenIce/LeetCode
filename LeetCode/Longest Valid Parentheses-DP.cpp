class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size()+1,0);
        int res=0;
        for (int i=0;i<s.size();i++) {
            if (i-1>=0&&s[i]==')'&&s[i-1]=='(') {
                dp[i]=i-2>=0 ? dp[i-2]+2 : 2;
            }
            else if (i-1>=0&&s[i]==')'&&s[i-1]==')') {
                if (i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
                    dp[i]=i-dp[i-1]-2>=0?dp[i-1]+dp[i-dp[i-1]-2]+2:dp[i-1]+2;
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
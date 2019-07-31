class Solution {
public:
    int getpos(int x,int y) {
        int t=0;
        for (int i=0;i<x;i++) {
            t=t+i+1;
        }
        return t+y;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size()==0)
            return 0;
        vector<int> dp;
        int ma=getpos(triangle.size()-1,triangle[triangle.size()-1].size()-1);
        for (int i=0;i<=ma;i++)
            dp.push_back(INT_MAX);
        dp[0]=triangle[0][0];
        for (int i=0;i<triangle.size()-1;i++) {
            for (int j=0;j<triangle[i].size();j++) {
                dp[getpos(i+1,j)]=min(dp[getpos(i+1,j)],dp[getpos(i,j)]+triangle[i+1][j]);
                dp[getpos(i+1,j+1)]=min(dp[getpos(i+1,j+1)],dp[getpos(i,j)]+triangle[i+1][j+1]);
            }
        }
        int mm=dp[ma];
        for (int i=ma+1-triangle[triangle.size()-1].size();i<ma;i++) {
            mm=min(dp[i],mm);
        }
        return mm;
    }
};
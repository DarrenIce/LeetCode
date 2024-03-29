class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> sum(n,vector<int>(m,0));
        sum[0][0]=grid[0][0];
        for (int i=1;i<m;i++)
            sum[0][i]=sum[0][i-1]+grid[0][i];
        for (int i=1;i<n;i++)
            sum[i][0]=sum[i-1][0]+grid[i][0];
        for (int i=1;i<n;i++)
        {
            for (int j=1;j<m;j++)
            {
                sum[i][j]=min(sum[i-1][j],sum[i][j-1])+grid[i][j];
            }
        }
        return sum[n-1][m-1];
    }
};
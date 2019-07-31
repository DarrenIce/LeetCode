class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<long>> count(n,vector<long>(m,0));
        for (int i=0;i<m;i++)
        {
            if (obstacleGrid[0][i]==0)
                count[0][i]=1;
            else
                break;
        }
        for (int i=0;i<n;i++)
        {
            if (obstacleGrid[i][0]==0)
                count[i][0]=1;
            else
                break;
        }
        for (int i=1;i<n;i++)
        {
            for (int j=1;j<m;j++)
            {
                if (obstacleGrid[i][j]==0)
                    count[i][j]=count[i-1][j]+count[i][j-1];
                else
                    count[i][j]=0;
            }
        }
        return count[n-1][m-1];
    }
};
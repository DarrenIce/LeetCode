class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int num=0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j]=='1') {
                    num++;
                    dfs(grid,i,j);
                }
            }
        }
        return num;
    }
    bool isisland(vector<vector<char>>& grid,int i,int j) {
        return (i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]=='1');
    }
    void dfs(vector<vector<char>>& grid,int i,int j) {
        if (isisland(grid,i,j)) {
            grid[i][j]='.';
            dfs(grid,i-1,j);
            dfs(grid,i+1,j);
            dfs(grid,i,j-1);
            dfs(grid,i,j+1);
        }
    }
};
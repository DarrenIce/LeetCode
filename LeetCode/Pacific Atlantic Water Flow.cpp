class Solution {
public:
    pair<int,int> dir[4]={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<bool>>& visit) {
        for (auto& a:dir) {
            int nx=i+a.first,ny=j+a.second;
            if (nx>=0&&nx<matrix.size()&&ny>=0&&ny<matrix[0].size()&&!visit[nx][ny]&&matrix[nx][ny]>=matrix[i][j]) {
                visit[nx][ny]=true;
                dfs(matrix,nx,ny,visit);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.empty())
            return res;
        vector<vector<bool>> visit1(matrix.size(),vector<bool>(matrix[0].size()));
        vector<vector<bool>> visit2(matrix.size(),vector<bool>(matrix[0].size()));
        for (int i=0;i<matrix.size();i++) {
            if (!visit1[i][0])
                visit1[i][0]=true;
                dfs(matrix,i,0,visit1);
            if (!visit2[i].back())
                visit2[i].back()=true;
                dfs(matrix,i,matrix[0].size()-1,visit2);
        }
        for (int i=0;i<matrix[0].size();i++) {
            if (!visit1[0][i])
                visit1[0][i]=true;
                dfs(matrix,0,i,visit1);
            if (!visit2.back()[i])
                visit2.back()[i]=true;
                dfs(matrix,matrix.size()-1,i,visit2);
        }
        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[0].size();j++) {
                if (visit1[i][j]&&visit2[i][j]) {
                    res.push_back(vector<int>{i,j});
                }
            }
        }
        return res;
    }
};
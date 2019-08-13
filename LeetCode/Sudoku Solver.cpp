class Solution {
public:
    bool row[9][9]={false};
    bool column[9][9]={false};
    bool block[9][9]={false};
    void solveSudoku(vector<vector<char>>& board) {
        int n=0;
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j]=='.') continue;
                int num=board[i][j]-'0'-1;
                int b=i/3*3+j/3;
                row[i][num]=true;
                column[j][num]=true;
                block[b][num]=true;
                n++;
            }
        }
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>>& board,int i,int j) {
        if (j==9) {
            if (i==8)
                return true;
            else {
                j=0;
                ++i;
            }
        }
        if (board[i][j]=='.') {
            int b=i/3*3+j/3;
            for (int k=0;k<9;k++) {
                if (!(row[i][k]||column[j][k]||block[b][k])) {
                    board[i][j]=k+'0'+1;
                    row[i][k]=column[j][k]=block[b][k]=true;
                    if (dfs(board,i,j+1))
                        return true;
                    board[i][j]='.';
                    row[i][k]=column[j][k]=block[b][k]=false;
                }
            }
            return false;
        }
        return dfs(board,i,j+1);
    }
};
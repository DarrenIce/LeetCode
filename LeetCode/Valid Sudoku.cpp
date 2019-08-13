class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={false};
        bool column[9][9]={false};
        bool block[9][9]={false};
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j]=='.') continue;
                int num=board[i][j]-'0'-1;
                int b=i/3*3+j/3;
                if (row[i][num]||column[j][num]||block[b][num])
                    return false;
                row[i][num]=column[j][num]=block[b][num]=true;
            }
        }
        return true;
    }
};
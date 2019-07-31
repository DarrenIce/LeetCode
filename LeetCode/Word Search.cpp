class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                if (dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,string& word,int x, int y, int pos)
    {
        if (pos==word.size())
            return true;
        if (x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y]=='0')
            return false;
        if (board[x][y]!=word[pos])
            return false;
        board[x][y]='0';
        bool res=(dfs(board,word,x+1,y,pos+1)||dfs(board,word,x,y+1,pos+1)||dfs(board,word,x-1,y,pos+1)||dfs(board,word,x,y-1,pos+1));
        board[x][y]=word[pos];
        return res;
    }
};
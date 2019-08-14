class Solution {
public:
    void dfs(int n, int i, vector<bool>& row, vector<bool>& column, vector<bool>& diag1,vector<bool>& diag2,int& count) {
      if (i == n) {
        count++;
        return;
      }
      for (int j = 0; j < n; j++) {
        if (row[i] && column[j] && diag1[j - i + n - 1]&&diag2[i+j]) {
          row[i] = column[j] = diag1[j - i + n - 1] =diag2[i+j]= false;
          dfs(n, i + 1, row, column, diag1,diag2,count);
          row[i] = column[j] = diag1[j - i + n - 1] = diag2[i+j]=true;
        }
      }
    }
    int totalNQueens(int n) {
        vector<bool> row(n, true);
        vector<bool> column(n, true);
        vector<bool> diag1(2 * n - 1, true);
        vector<bool> diag2(2*n-1,true);
        if (n==0)
            return 0;
        int count=0;
        dfs(n,0,row,column,diag1,diag2,count);
        return count;
    }
};
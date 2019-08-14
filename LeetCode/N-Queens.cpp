class Solution {
public:
void dfs(int n, int i, vector<bool>& row, vector<bool>& column, vector<bool>& diag1,vector<bool>& diag2, set<vector<string>>& res, vector<string>& c) {
  if (i == n) {
    res.insert(c);
    return;
  }
  for (int j = 0; j < n; j++) {
    if (row[i] && column[j] && diag1[j - i + n - 1]&&diag2[i+j]) {
      row[i] = column[j] = diag1[j - i + n - 1] =diag2[i+j]= false;
      c[i][j] = 'Q';
      dfs(n, i + 1, row, column, diag1,diag2, res,c);
      c[i][j] = '.';
      row[i] = column[j] = diag1[j - i + n - 1] = diag2[i+j]=true;
    }
  }
}



vector<vector<string>> solveNQueens(int n) {
  vector<bool> row(n, true);
  vector<bool> column(n, true);
  vector<bool> diag1(2 * n - 1, true);
  vector<bool> diag2(2*n-1,true);
  set<vector<string>> temp;
  if (n == 0)
    return vector<vector<string>>{{}};
  vector<string> c(n, string(n, '.'));
  dfs(n, 0, row, column, diag1,diag2, temp,c);
  return vector<vector<string>>(temp.begin(),temp.end());
}
};
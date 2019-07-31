class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> res;
      if (numRows == 0)
        return res;
      else if (numRows == 1) {
        res.push_back({ 1 });
        return res;
      }
      else if (numRows == 2) {
        res.push_back({ 1 });
        res.push_back({ 1,1 });
        return res;
      }
      res.push_back({ 1 });
      res.push_back({ 1,1 });
      for (int i = 2; i < numRows; i++) {
        vector<int> temp;
        temp.push_back(1);
        for (int j = 1; j < i; j++) {
          temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }
        temp.push_back(1);
        res.push_back(temp);
      }
      return res;
}
};
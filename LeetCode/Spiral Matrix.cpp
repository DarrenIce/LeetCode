class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int r=matrix.size();
        if (!r)
            return res;
        int c=matrix[0].size();
        if (!c)
            return res;
        vector<vector<int>> step{{0,1},{1,0},{0,-1},{-1,0}};
        int dic=0;
        vector<int> s{c,r-1};
        int rr=0,cc=-1;
        while (s[dic%2])
        {
            for (int i=0;i<s[dic%2];i++)
            {
                rr+=step[dic][0];
                cc+=step[dic][1];
                res.push_back(matrix[rr][cc]);
            }
            s[dic%2]--;
            dic=(dic+1)%4;
        }
        return res;
    }
};
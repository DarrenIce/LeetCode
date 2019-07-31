class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int k=1,i=0;
        while (k<=n*n)
        {
            int j=i;
            while (j<n-i)
                res[i][j++]=k++;
            j=i+1;
            while (j<n-i)
                res[j++][n-1-i]=k++;
            j=n-i-2;
            while (j>i)
                res[n-1-i][j--]=k++;
            j=n-1-i;
            while (j>i)
                res[j--][i]=k++;
            i++;
        }
        return res;
    }
};
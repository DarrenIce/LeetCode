class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0||matrix[0].size()==0)
            return false;
        int l=0,r=matrix.size()*matrix[0].size()-1;
        int d=matrix[0].size();
        while (l<r)
        {
            int mid=(l+r)/2;
            if (matrix[mid/d][mid%d]==target)
                return true;
            else if (matrix[mid/d][mid%d]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        if (matrix[l/d][l%d]==target)
            return true;
        else
            return false;
    }
};
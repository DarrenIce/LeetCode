class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex==0) {
            vector<int> t{1};
            return t;
        } else if (rowIndex==1) {
            vector<int> t{1,1};
            return t;
        } else {
            vector<int> res={1,1};
            for (int i=2;i<=rowIndex;i++)
            {
                vector<int> temp;
                temp.push_back(1);
                for (int j=1;j<i;j++)
                {
                    temp.push_back(res[j-1]+res[j]);
                }
                temp.push_back(1);
                res=temp;
            }
            return res;
        }
    }
};
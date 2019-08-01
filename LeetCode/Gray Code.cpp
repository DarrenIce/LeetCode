class Solution {
public:
    void bt(int n,vector<int>& res) {
        if (n==0) {
            res.push_back(0);
            return;
        } else {
            bt(n-1,res);
            for (int i=0;i<res.size();i++) {
                res[i] <<=1;
            }
            for (int i=res.size()-1;i>=0;i--) {
                res.push_back(res[i]+1);
            }
        }
    }
    vector<int> grayCode(int n) {
        if (n==0)
            return vector<int> {0};
        vector<int> res;
        bt(n,res);
        return res;
    }
};
class Solution {
public:
    void bt(int n,int lpn,int s,string& ans, vector<string>& res) {
        if (ans.size()==2*n) {
            if (find(res.begin(),res.end(),ans)==res.end())
                res.push_back(ans);
            return;
        } else {
            if (s>0) {
                ans+=')';
                bt(n,lpn,s-1,ans,res);
                ans.pop_back();
            }
            if (lpn<n) {
                ans+='(';
                bt(n,lpn+1,s+1,ans,res);
                ans.pop_back();
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n==0)
            return res;
        string ans;
        bt(n,0,0,ans,res);
        return res;
    }
};
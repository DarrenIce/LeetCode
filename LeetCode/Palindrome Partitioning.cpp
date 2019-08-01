class Solution {
public:
    bool ispld(string s) {
        int l=0,r=s.size()-1;
        while (l<r) {
            if (s[l]!=s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
    void bt(string s,int k,vector<string>& ans,vector<vector<string>>& res) {
        if (k==s.size()) {
            res.push_back(ans);
        } else {
            for (int i=1;i<=s.size()-k;i++) {
                string temp=s.substr(k,i);
                if (ispld(temp)) {
                    ans.push_back(temp);
                    bt(s,k+i,ans,res);
                    ans.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if (s.size()==0)
            return vector<vector<string>>();
        vector<vector<string>> res;
        vector<string> ans;
        bt(s,0,ans,res);
        return res;
    }
};
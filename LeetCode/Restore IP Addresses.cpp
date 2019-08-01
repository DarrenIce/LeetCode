class Solution {
public:
    void bt(string s,int t,int k,string& ans,vector<string>& res) {
        if (t==3) {
            if (k<s.size()) {
                string temp=s.substr(k);
                if ((temp.size()>1&&temp[0]!='0')||temp.size()==1) {
                    long num=atol(temp.c_str());
                    if (num>=0&&num<=255) {
                        ans+=s.substr(k);
                        res.push_back(ans);
                        ans=ans.substr(0,k+3);
                        return;
                    }
                }
            }
        } else {
            for (int i=1;i<=3;i++) {
                if (k+i<s.size()) {
                    if ((i>1&&s[k]!='0')||i==1) {
                        int n=atol(s.substr(k,i).c_str());
                        if (n>=0&&n<=255) {
                            ans+=s.substr(k,i);
                            ans+='.';
                            bt(s,t+1,k+i,ans,res);
                            ans=ans.substr(0,ans.size()-1-i);
                        }
                    }
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size()<4)
            return vector<string>();
        vector<string> res;
        string ans;
        bt(s,0,0,ans,res);
        return res;
    }
};
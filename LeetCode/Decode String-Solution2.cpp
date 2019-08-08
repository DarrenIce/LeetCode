class Solution {
public:
    string decodeString(string s) {
        if (s.size()==0)
            return s;
        stack<char> sc;
        for (int i=0;i<s.size();i++) {
            if (s[i]!=']')
                sc.push(s[i]);
            else {
                char c=sc.top();
                string rep;
                while (c!='[') {
                    rep=c+rep;
                    sc.pop();
                    c=sc.top();
                }
                string num;
                sc.pop();
                c=sc.top();
                while ('0'<=c&&c<='9') {
                    num=c+num;
                    sc.pop();
                    if (!sc.empty())
                        c=sc.top();
                    else
                        break;
                }
                for (int j=0;j<stoi(num);j++) {
                    for (int k=0;k<rep.size();k++) {
                        sc.push(rep[k]);
                    }
                }
            }
        }
        string res;
        for (int i=sc.size();i>0;i--) {
            res=sc.top()+res;
            sc.pop();
        }
        return res;
    }
};
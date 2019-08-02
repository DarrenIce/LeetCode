class Solution {
public:
    bool dfs(string num,int start,string s1,string s2) {
        if (start==num.size())
            return true;
        long t1=stol(s1),t2=stol(s2);
        string sum=to_string(t1+t2);
        if (sum.size()>num.size()-start)
            return false;
        for (int i=0;i<sum.size();i++)
            if (sum[i]!=num[start+i])
                return false;
        return dfs(num,start+sum.size(),s2,sum);
    }
    bool isAdditiveNumber(string num) {
        if (num.size()<3)
            return false;
        for (int i=1;i<=num.size()/2;i++) {
            if (num[0]=='0'&&i>1)
                return false;
            for (int j=1;j<=(num.size()-i)/2;j++) {
                if (num[i]=='0'&&j>1)
                    break;
                string s1=num.substr(0,i);
                string s2=num.substr(i,j);
                if (dfs(num,i+j,s1,s2))
                    return true;
            }
        }
        return false;
    }
};
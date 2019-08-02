class Solution {
public:
    bool dfs(string& s,int start,string s1,string s2,vector<int>& ans) {
        if (s.size()==start)
            return true;
        long l1=stol(s1);
        long l2=stol(s2);
        string sum=to_string(l1+l2);
        if (sum.size()>(s.size()-start))
            return false;
        if ((l1+l2)>INT_MAX)
            return false;
        for (int i=0;i<sum.size();i++)
            if (sum[i]!=s[start+i])
                return false;
        ans.push_back(stol(sum));
        if (dfs(s,start+sum.size(),s2,sum,ans))
            return true;
        else {
            ans.pop_back();
            return false;
        }
        
    }
    vector<int> splitIntoFibonacci(string S) {
        if (S.size()==0)
            return vector<int> {};
        string s1,s2;
        vector<int> ans;
        for (int i=1;i<=S.size()/2;i++) {
            if (S[0]=='0'&&i>1)
                return vector<int> {};
            if (i>9)
                return vector<int> {};
            for (int j=1;j<=(S.size()-i)/2;j++) {
                if (S[i]=='0'&&j>1)
                    break;
                if (j>9)
                    break;
                s1=S.substr(0,i);
                s2=S.substr(i,j);
                ans.push_back(stol(s1));
                ans.push_back(stol(s2));
                if (dfs(S,i+j,s1,s2,ans))
                    return ans;
                ans.pop_back();
                ans.pop_back();
            }
        }
        return vector<int> {};
    }
};
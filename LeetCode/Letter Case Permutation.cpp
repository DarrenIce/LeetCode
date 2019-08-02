class Solution {
public:
    void dfs(int n,int k,vector<int>& mapp,string& s,vector<string>& ans) {
        if (n==k)
            ans.push_back(s);
        else {
            dfs(n,k+1,mapp,s,ans);
            if (s[mapp[k]]>='a'&&s[mapp[k]]<='z')
                s[mapp[k]]+='A'-'a';
            else if (s[mapp[k]]>='A'&&s[mapp[k]]<='Z')
                s[mapp[k]]+='a'-'A';
            dfs(n,k+1,mapp,s,ans);
        }
    }
    vector<string> letterCasePermutation(string S) {
        int letter_num=0;
        vector<int> mapp(S.size(),0);
        for (int i=0;i<S.size();i++) {
            if (('a'<=S[i]&&S[i]<='z')||('A'<=S[i]&&S[i]<='Z')) {
                mapp[letter_num++]=i;
            }   
        }
        vector<string> ans;
        dfs(letter_num,0,mapp,S,ans);
        return ans;
        
    }
};
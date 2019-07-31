class Solution {
public:
    void backtracking(string digits,int i,map<char,string>& m,string& ans,vector<string>& res) {
        if (i==digits.size()) {
            res.push_back(ans);
            return;
        } else {
            for (int k=0;k<m[digits[i]].size();k++) {
                ans+=m[digits[i]][k];
                backtracking(digits,i+1,m,ans,res);
                ans.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string> res;
        if (digits.size()==0)
            return res;
        string ans;
        backtracking(digits,0,m,ans,res);
        return res;
    }
    
};
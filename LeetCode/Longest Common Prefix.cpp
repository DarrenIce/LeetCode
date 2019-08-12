class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty())
            return res;
        for (int i=0;i<strs[0].size();i++) {
            for (int j=1;j<strs.size();j++) {
                if (strs[j].size()>i&&strs[j][i]==strs[0][i])
                    continue;
                else
                    return res;
            }
            res+=strs[0][i];
        }
        return res;
    }
};
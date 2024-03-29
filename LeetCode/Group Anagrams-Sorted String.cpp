class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (auto& str:strs) {
            string temp=str;
            sort(temp.begin(),temp.end());
            m[temp].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& mm:m)
            res.push_back(mm.second);
        return res;
    }
};
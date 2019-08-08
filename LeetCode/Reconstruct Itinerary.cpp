class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for (auto &t : tickets)
            mp[t[0]].insert(t[1]);
        vector<string> path;
        string name = "JFK";
        dfs(name,mp,path);
        return path;
    }
    void dfs(string name,unordered_map<string, multiset<string>>& mp,vector<string>& path) {
        while (mp[name].size()) {
            string temp=*(mp[name].begin());
            mp[name].erase(mp[name].begin());
            dfs(temp,mp,path);
        }
        path.insert(path.begin(),name);
    }
};
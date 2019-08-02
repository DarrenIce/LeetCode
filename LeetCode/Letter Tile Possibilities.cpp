class Solution {
public:
    void dfs(string& tiles, int n,int k,vector<int>& mapp,string& res,unordered_set<string>& ans) {
        if (n==k)
            ans.insert(res);
        else {
            for (int i=k;i<tiles.size();i++) {
                swap(mapp[i],mapp[k]);
                res+=tiles[mapp[k]];
                dfs(tiles,n,k+1,mapp,res,ans);
                res=res.substr(0,res.size()-1);
                swap(mapp[i],mapp[k]);
            }
        }
    }
    int numTilePossibilities(string tiles) {
        if (tiles.size()==0)
            return 0;
        unordered_set<string> ans;
        string res;
        vector<int> mapp(tiles.size(),0);
        for (int i=0;i<tiles.size();i++)
            mapp[i]=i;
        for (int i=1;i<=tiles.size();i++) {
            dfs(tiles,i,0,mapp,res,ans);
        }
        return ans.size();
    }
};
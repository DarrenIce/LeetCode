class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        dfs(candidates.begin(),current,res,candidates,target);
        return res;
    }
    
    void dfs(vector<int>::iterator n,vector<int>& current,vector<vector<int>>& res,vector<int>& candidates,int target) {
        if (!target) {
            res.push_back(current);
        }
        else if (target>0) {
            for (;n!=candidates.end()&&*n<=target;n++) {
                current.push_back(*n);
                dfs(n+1,current,res,candidates,target-*n);
                current.pop_back();
                while (n+1!=candidates.end()&&*n==*(n+1))
                    n++;
            }
        }
    }
};
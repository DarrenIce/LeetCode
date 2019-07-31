class Solution {
public:
    void dfs(vector<int>& nums, int it, vector<int>& temp, vector<vector<int>>& res)
    {
        res.push_back(temp);
        if (it==nums.size())
            return;
        for (;it<nums.size();it++)
        {
            temp.push_back(nums[it]);
            dfs(nums,it+1,temp,res);
            temp.pop_back();
            while (it<nums.size()-1&&nums[it]==nums[it+1])
                ++it;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int it=0;
        vector<int> temp;
        if (nums.size()==0)
            return res;
        sort(nums.begin(),nums.end());
        dfs(nums,it,temp,res);
        return res;
    }
};
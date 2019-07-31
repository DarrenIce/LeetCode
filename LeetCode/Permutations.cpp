class Solution {
public:
    void bt(vector<int>& nums,int s,vector<int>& ans,vector<vector<int>>& res) {
        if (s==nums.size())
        {
            res.push_back(ans);
            return;
        } else {
            for (int i=s;i<nums.size();i++) {
                ans.push_back(nums[i]);
                swap(nums[i],nums[s]);
                bt(nums,s+1,ans,res);
                swap(nums[i],nums[s]);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()==0)
            return res;
        vector<int> ans;
        bt(nums,0,ans,res);
        return res;
    }
};
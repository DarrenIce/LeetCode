class Solution {
public:
    set<vector<int>> g;
    void bt(vector<int>& nums,int s) {
        if (s==nums.size())
        {
            g.insert(nums);
            return;
        } else {
            for (int i=s;i<nums.size();i++) {
                while (nums.size()>=2&&i<nums.size()-2&&nums[i]==nums[i+1]) {
                    ++i;
                }
                swap(nums[i],nums[s]);
                bt(nums,s+1);
                swap(nums[i],nums[s]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> a;
        if (nums.size()==0)
            return a;
        bt(nums,0);
        vector<vector<int>> res(g.begin(),g.end());
        return res;
    }
};
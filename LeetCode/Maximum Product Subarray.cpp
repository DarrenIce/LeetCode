class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int cur_max=nums[0];
        int cur_min=nums[0];
        int pre_max=nums[0];
        int pre_min=nums[0];
        int ans=nums[0];
        for (int i=1;i<n;i++) {
            cur_max=max(max(pre_max*nums[i],pre_min*nums[i]),nums[i]);
            cur_min=min(min(pre_max*nums[i],pre_min*nums[i]),nums[i]);
            ans=max(cur_max,ans);
            pre_max=cur_max;
            pre_min=cur_min;
        }
        return ans;
    }
};
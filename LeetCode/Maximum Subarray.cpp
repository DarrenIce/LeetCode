class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxnum(n);
        maxnum[0]=nums[0];
        int maxs=nums[0];
        for (int i=1;i<n;i++)
        {
            maxnum[i]=nums[i]+(maxnum[i-1]>0?maxnum[i-1]:0);
            maxs=max(maxs,maxnum[i]);
        }
        return maxs;
    }
};
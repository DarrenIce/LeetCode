class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size()==1)
            return nums[0];
        if (nums.size()==2)
            return nums[0]>nums[1]?nums[1]:nums[0];
        int l=0,r=nums.size()-1;
        while (l<r) {
            int m=(l+r)/2;
            if (nums[l]<nums[r])
                return nums[l];
            if (nums[m]>nums[l])
                l=m;
            else if (nums[m]<nums[l])
                r=m;
            else
                l++;
        }
        return min(nums[l],nums[r]);
    }
};
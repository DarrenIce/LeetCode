class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size()==1)
            return nums[0];
        else if (nums.size()==2)
            return nums[0]>nums[1]?nums[1]:nums[0];
        int min=nums[0];
        int left=0,right=nums.size()-1;
        while (left<=right) {
            int mid=(left+right)/2;
            if (nums[mid]>min) {
                left=mid+1;
            }
            else {
                right=mid-1;
                min=nums[mid];
            }
        }
        return min;
    }
};
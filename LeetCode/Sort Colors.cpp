class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if (not n)
            return;
        int front=-1,back=n;
        for (int i=0;i<back;i++)
        {
            if (nums[i]==0)
            {
                swap(nums[i],nums[++front]);
            }
            else if (nums[i]==2)
            {
                swap(nums[i--],nums[--back]);
            }
        }
    }
};


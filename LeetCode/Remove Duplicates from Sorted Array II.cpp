class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        auto j=nums.begin();
        for (int i=1;i<nums.size();i++)
        {
            if (nums[i]==nums[i-1])
                count++;
            else
                count=0;
            if (count>=2)
            {
                nums.erase(j);
                i--;
            }
            else
                j++;
        }
        return nums.size();
    }
};
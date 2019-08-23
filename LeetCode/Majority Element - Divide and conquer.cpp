class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        return dq(nums, 0, nums.size() - 1);
    }
    int dq(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return nums[l];
        if (l < r)
        {
            int m = (l + r) / 2;
            int left = dq(nums, l, m);
            int right = dq(nums, m + 1, r);
            if (left == right)
                return left;
            else
            {
                int count1 = 0, count2 = 0;
                for (int i = l; i <= r; i++)
                {
                    if (nums[i] == left)
                        count1++;
                    else if (nums[i] == right)
                        count2++;
                }
                if (count1 > count2)
                    return left;
                else
                    return right;
            }
        }
        return 0;
    }
};
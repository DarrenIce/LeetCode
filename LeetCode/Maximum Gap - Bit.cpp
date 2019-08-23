class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        int maxnum = nums.front();
        for (auto num : nums)
            maxnum = max(maxnum, num);
        int bit = 0;
        while (maxnum >= pow(10, bit))
            bit++;
        for (int i = 0; i < bit; i++)
        {
            vector<vector<int>> bucket(10);
            for (auto num : nums)
            {
                int index = (int)(num / pow(10, i)) % 10;
                bucket[index].push_back(num);
            }
            nums.clear();
            for (auto bk : bucket)
            {
                nums.insert(nums.end(), bk.begin(), bk.end());
            }
        }
        int maxGap = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        return maxGap;
    }
};
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        int maxval = nums.front();
        int minval = nums.front();
        for (auto num : nums)
        {
            maxval = max(maxval, num);
            minval = min(minval, num);
        }
        int bucketSize = max(1, (maxval - minval) / ((int)nums.size() - 1));
        int bucketNum = ceil((maxval - minval + 1) / (float)bucketSize);
        vector<vector<int>> bucket(bucketNum);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == maxval)
            {
                bucket.back().push_back(nums[i]);
                continue;
            }
            int index = (nums[i] - minval) / bucketSize;
            bucket[index].push_back(nums[i]);
        }
        nums.clear();
        for (auto bk : bucket)
        {
            sort(bk.begin(), bk.end());
            nums.insert(nums.end(), bk.begin(), bk.end());
        }
        int maxGap = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        return maxGap;
    }
};
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto num : nums)
        {
            if (m.find(num) == m.end())
                m[num] = 1;
            else
                m[num]++;
        }
        int mt = nums.size() / 2;
        for (auto mm : m)
        {
            if (mm.second > mt)
                return mm.first;
        }
        return 0;
    }
};
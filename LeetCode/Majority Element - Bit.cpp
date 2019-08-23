class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        vector<vector<int>> table(32, vector<int>(2, 0));
        for (int i = 0; i < 32; i++)
        {
            int mask = 1 << i;
            for (auto num : nums)
            {
                if (num & mask)
                    table[i][1]++;
                else
                    table[i][0]++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if (table[i][1] > table[i][0])
                res = res ^ (1 << i);
        }
        return res;
    }
};
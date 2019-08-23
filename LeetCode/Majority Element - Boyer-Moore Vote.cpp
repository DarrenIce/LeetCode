class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int m, count = 0;
        for (auto x : nums)
        {
            if (!count)
            {
                ++count;
                m = x;
            }
            else
            {
                if (m == x)
                    ++count;
                else
                    --count;
            }
        }
        return m;
    }
};
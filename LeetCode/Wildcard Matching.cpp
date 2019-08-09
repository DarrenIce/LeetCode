class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int lps = -1, lss = -1, i = 0, j = 0;
        while (j < s.size())
        {
            if (i < p.size() && p[i] == '*')
            {
                lps = ++i;
                lss = j;
            }
            else if (i < p.size() && (s[j] == p[i] || p[i] == '?'))
            {
                ++i;
                ++j;
            }
            else
            {
                if (lps == -1)
                    return false;
                j = ++lss;
                i = lps;
            }
        }
        while (p[i] == '*')
            ++i;
        return i == p.size();
    }
};
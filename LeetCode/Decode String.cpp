class Solution
{
public:
    string findsub(string &s, int k)
    {
        string temp;
        for (int i = k - 1; i >= 0; i--)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                temp.insert(temp.begin(), s[i]);
            else
                break;
        }
        return temp;
    }
    int findnum(string &s, int k)
    {
        string temp;
        int i = k;
        for (; i > 0; i--)
            if (s[i] == '[')
                break;
        i--;
        for (; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
                temp.insert(temp.begin(), s[i]);
            else
                break;
        }
        return stoi(temp);
    }
    void dfs(string &s, int &k)
    {
        string re;
        for (; k < s.size(); k++)
        {
            if (s[k] == '[')
            {
                dfs(s, ++k);
            }
            else if (s[k] == ']')
            {
                re = findsub(s, k);
                int num = findnum(s, k);
                int loc = k - re.size() - 1 - to_string(num).size();
                string s1 = s.substr(0, loc);
                string s2 = s.substr(k + 1);
                s = s1;
                for (int i = 0; i < num; i++)
                    s += re;
                s += s2;
                int pre = 2 + to_string(num).size() + re.size();
                k = k - pre + num * re.size();
            }
        }
    }
    string decodeString(string s)
    {
        if (s.size() == 0)
            return s;
        int k = 0;
        dfs(s, k);
        return s;
    }
};
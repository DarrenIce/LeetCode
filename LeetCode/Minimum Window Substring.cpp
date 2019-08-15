class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mmap(128,0);
        for (auto c:t)
            mmap[c]++;
        int len=-1,start=0,left=0,right=0,remains=t.size();
        while (right<s.size()) {
            if (--mmap[s[right++]]>=0)
                --remains;
            while (remains==0) {
                if (len==-1) {
                    len=right-left;
                    start=left;
                }
                else if (right-left<len) {
                    len=right-left;
                    start=left;
                }
                if (++mmap[s[left++]]>0)
                    ++remains;
            }
        }
        return len==-1?"":s.substr(start,len);
    }
};
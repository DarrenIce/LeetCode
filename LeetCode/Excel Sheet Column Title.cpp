class Solution {
public:
    string convertToTitle(int n) {
        string res;
        long long nn=n;
        while (nn>0) {
            res=(char)('A'+(nn+25)%26)+res;
            nn=(nn-1)/26;
        }
        return res;
    }
};
class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size()==0||numRows==1)
            return s;
        int ival=2*numRows-2;
        string ss;
        for (int i=0;i<numRows;i++) {
            int j=i;
            int count=0;
            while (j<s.size()) {
                ss+=s[j];
                if (i==0||i==numRows-1)
                    j+=ival;
                else
                    j+=count%2==0?ival-2*i:2*i;
                count++;
            }
        }
        return ss;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size()==0)
            return 0;
        int s=ratings.size();
        int sum=1,pre_candy=1,last_inc=1,dec_len=0;
        for (int i=1;i<s;i++) {
            if (ratings[i]>ratings[i-1]) {
                sum+=++pre_candy;
                last_inc=pre_candy;
                dec_len=0;
            }
            else if (ratings[i]==ratings[i-1]) {
                sum++;
                last_inc=pre_candy=1;
                dec_len=0;
            }
            else {
                sum+=++dec_len>=last_inc?1:0;
                sum+=dec_len;
                pre_candy=1;
            }
        }
        return sum;
    }
};
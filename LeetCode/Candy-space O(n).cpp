class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size()==0)
            return 0;
        int s=ratings.size();
        vector<int> candy(s,1);
        for (int i=1;i<s;i++) {
            if (ratings[i]>ratings[i-1])
                candy[i]=candy[i-1]+1;
        }
        for (int i=s-2;i>=0;i--) {
            if (ratings[i]>ratings[i+1])
                candy[i]=max(candy[i],candy[i+1]+1);
        }
        int sum=0;
        for (int i=0;i<s;i++)
            sum+=candy[i];
        return sum;
    }
};
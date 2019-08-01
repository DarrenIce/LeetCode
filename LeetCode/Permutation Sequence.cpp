class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fit(n+1,1);
        for (int i=1;i<=n;i++)
            fit[i]=fit[i-1]*i;
        vector<int> able(n+1,1);
        string ans;
        int bit=n-1;
        while (bit>=0) {
            int i=1;
            for (i=1;i<=n;i++) {
                if (able[i]==0)
                    continue;
                if (fit[bit]>=k)
                    break;
                k-=fit[bit];
            }
            able[i]=0;
            ans+=to_string(i);
            --bit;
        }
        return ans;
    }
};
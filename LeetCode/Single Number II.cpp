class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for (int i=0;i<32;i++) {
            int ans=0;
            for (auto j:nums) {
                ans+=1&j>>i;
            }    
            if (ans%3!=0)
                res=res|1<<i;
        }
        return res;
    }
};
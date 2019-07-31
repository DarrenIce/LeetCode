class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,curmax=-1;
        for (int i=prices.size()-1;i>=0;i--) {
            curmax=max(curmax,prices[i]);
            if (curmax>prices[i])
            {
                profit+=(curmax-prices[i]);
                curmax=prices[i];
            }
        }
        return profit;
    }
};
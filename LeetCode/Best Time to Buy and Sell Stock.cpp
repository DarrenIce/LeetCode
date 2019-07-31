class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        vector<int> lowest_in_left=prices;
        vector<int> highest_in_right=prices;
        for (int i=1;i<prices.size();i++) {
            lowest_in_left[i]=min(lowest_in_left[i-1],prices[i]);
        }
        for (int i=prices.size()-2;i>=0;i--) {
            highest_in_right[i]=max(highest_in_right[i+1],prices[i]);
        }
        for (int i=0;i<prices.size();i++) {
            profit=max(profit,highest_in_right[i]-lowest_in_left[i]);
        }
        return profit;
    }
};
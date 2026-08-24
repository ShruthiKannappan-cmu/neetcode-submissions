class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = size(prices);
        int maxl = prices[n-1];
        int profit = 0;
        for(int i = n-2;i>=0;i--){
            int p = prices[i];
            profit = max(profit,maxl-p);
            maxl = max(maxl,p);
        }
        return profit;
    }
};

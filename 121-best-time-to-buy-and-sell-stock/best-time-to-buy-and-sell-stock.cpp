class Solution {
public:
    int maxProfit(vector<int>& prices) {
         // code here
        int profit=0;
        int mini=prices[0];
        for(int i=0;i<prices.size();i++){
            profit=max(profit,prices[i]-mini);
            mini=min(prices[i],mini);
        }
        return profit;
    
    }
};
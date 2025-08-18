class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit       = 0;
        int minPricePast = prices[0];
        for (const auto& price : prices) {
            profit       = std::max(profit, price -  minPricePast);
            minPricePast = std::min(minPricePast, price);
        }
        return profit;
    }
};
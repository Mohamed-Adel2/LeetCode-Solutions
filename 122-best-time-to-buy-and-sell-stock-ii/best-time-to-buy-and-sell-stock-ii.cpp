class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int curr = 1e7;
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] < curr)
                curr = prices[i];
            else
                ans += prices[i] - curr, curr = prices[i];
        }
        return ans;
    }
};
class Solution {
public:
    int solve(int idx, bool buy, int k, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(idx >= n || !k)
            return 0;
        int& ret = dp[idx][buy][k];
        if(~ret)
            return ret;
        ret = 0;
        if(buy){
            ret = solve(idx + 1, !buy, k, n, prices, dp) - prices[idx];
            ret = max(ret, solve(idx + 1, buy, k, n, prices, dp));
        }
        else{
            ret = solve(idx + 1, !buy, k - 1, n, prices, dp) + prices[idx];
            ret = max(ret, solve(idx + 1, buy, k, n, prices, dp));
        }
        return ret;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, true, k, n, prices, dp);
    }
};
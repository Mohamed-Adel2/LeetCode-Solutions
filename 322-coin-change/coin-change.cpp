class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i)
            for (int j = 0; j <= amount - coins[i]; ++j)
                if (dp[j] != INT32_MAX)
                    dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
        return (dp[amount] != INT32_MAX ? dp[amount] - 1 : -1);
    }
};
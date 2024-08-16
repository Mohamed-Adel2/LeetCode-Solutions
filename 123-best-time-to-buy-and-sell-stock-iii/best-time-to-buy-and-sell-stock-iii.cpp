class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n), right(n);
        int mn = prices[0];
        for(int i = 0; i < n; ++i){    
            left[i] = max(left[i ? i - 1 : 0], prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        int mx = prices[n - 1];
        for(int i = n - 1; i >= 0; --i){
            right[i] = max(right[i < n - 1 ? i + 1 : i], mx - prices[i]);
            mx = max(mx, prices[i]);
        }
        int ans = max({left[n - 1], right[0], 0});
        for(int i = 0; i < n - 1; ++i){
            ans = max(left[i] + right[i + 1], ans);
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ptr = 0, mn = prices[0], mx = prices[0], n = prices.size();
        int ans = 0;
        while (ptr < n) {
            ptr++;
            if (ptr < n) {
                if (prices[ptr] < mn) {
                    ans = max(mx - mn, ans);
                    mn = mx = prices[ptr];
                } else {
                    mx = max(mx, prices[ptr]);
                }
            }
        }
        ans = max(mx - mn, ans);
        return ans;
    }
};
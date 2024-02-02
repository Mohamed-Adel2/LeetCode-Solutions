class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ptr = 0, mn = prices[0], mx = prices[0], n = prices.size();
        int ans = 0;
        while (ptr < n) {
            ptr++;
            if (ptr < n) {
                if (prices[ptr] < mx) {
                    ans += mx - mn;
                    mn = mx = prices[ptr];
                } else {
                    mx = prices[ptr];
                }
            }
        }
        ans += mx - mn;
        return ans;
    }
};
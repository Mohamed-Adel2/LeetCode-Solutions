class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn, mx, ans = prices[0], prices[0], 0
        for price in prices:
            if price > mx:
                mx = price
            elif price < mn:
                mn = mx = price
            ans = max(mx - mn, ans)
        return ans
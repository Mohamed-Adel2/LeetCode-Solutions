class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn, mx, ans = prices[0], prices[0], 0
        for price in prices:
            if price < mx:
                ans += (mx - mn)
                mx = mn = price
            elif price < mn:
                mn = mx = price
            elif price > mx:
                mx = price
        ans += (mx - mn)
        return ans
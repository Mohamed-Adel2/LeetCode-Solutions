class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo = 1, hi = 1e13;
        int ans = hi;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            long long needed = 0;
            for(int i = 0; i < piles.size(); ++i)
                needed += ((long long)piles[i] + mid - 1) / mid;
            if(needed <= h)
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        return ans;
    }
};
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int mn = nums[0], mx = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        int lo = mn, hi = mx;
        long long ans = 1e18;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            long long midCost = calc(nums, cost, mid), aboveCost = calc(nums, cost, mid + 1); 
            if(midCost < aboveCost){
                hi = mid - 1;
                ans = min(ans, midCost);
            }
            else{
                lo = mid + 1;
                ans = min(ans, aboveCost);
            }
        }
        return ans;
    }
    long long calc(vector<int>& nums, vector<int>& cost, int target){
        long long ret = 0;
        for(int i = 0; i < nums.size(); ++i)
            ret += abs(target - nums[i]) * (long long)cost[i];
        return ret;
    }
};
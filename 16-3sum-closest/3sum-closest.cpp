class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans= 1e9;
        for(int i = 0;i<nums.size() - 2;++i){
            int lo = i + 1, hi = nums.size() - 1;
            int need = target - nums[i];
            while(lo < hi){
                if(abs(target - ans) > abs(nums[lo] + nums[hi] + nums[i] - target))
                    ans = nums[lo] + nums[hi] + nums[i];
                if(nums[lo] + nums[hi] < need)
                    ++lo;
                else
                    --hi;
            }
        }
        return ans;
    }
};
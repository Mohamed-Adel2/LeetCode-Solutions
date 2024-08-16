class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back(), ans;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(check(nums, mid) < k)
                lo = mid + 1;
            else{
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }

    int check(vector<int>& nums, int val){
        int ret = 0, left = 0, right = 0;
        while(right < nums.size()){
            if(nums[right] - nums[left] > val)
                while(nums[right] - nums[++left] > val);
            ret += right - left;  
            ++right;
        }
        return ret;
    }
};
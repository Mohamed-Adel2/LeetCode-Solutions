class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 1, hi = nums.size() - 1, ans;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int cnt = 0;
            for(int i = 0;i<nums.size();++i)
                if(nums[i] < mid)
                    ++cnt;
            if(cnt <= mid - 1){
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, ans = 0;
        bool containsZero = false;
        while(right < nums.size()){
            if(nums[right] == 0 && containsZero)
                containsZero ^= (nums[left++] == 0);
            else
                containsZero |= (nums[right++] == 0);
            ans = max(ans, right - left - 1);
        }
        return ans;
    }
};
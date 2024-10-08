class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, zeros = 0, ans = 0;
        while(right < nums.size()){
            if(nums[right] == 0 && zeros == k)
                zeros -= (nums[left++] == 0);
            else
                zeros += (nums[right] == 0), ++right;
            ans = max(ans, right - left);
        }
        return ans;
    }
};
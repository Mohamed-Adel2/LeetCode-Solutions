class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, right = 0, ans = 0;
        while(right<nums.size()){
            ++freq[nums[right]];
            if(freq[nums[right]]>k){
                ans = max(ans, right-left);
                while(nums[left]!=nums[right]){
                    --freq[nums[left++]];
                }
                --freq[nums[left++]];
            }
            ++right;
        }
        return max(ans, right - left);
    }
};
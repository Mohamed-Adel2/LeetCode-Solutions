class Solution {
public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, right = 0, ans = 0;
        while (right < nums.size()) {
            if (++freq[nums[right]] > k)
                while (left < right && freq[nums[right]] > k)
                    --freq[nums[left++]];
            ++right;
            ans = max(ans, right - left);
        }
        return ans;
    }
};
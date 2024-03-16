class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size(), ans = 0, curr = 0;
        unordered_map<int, int> diff;
        diff[0] = 0;
        for (int i = 1; i <= n; ++i) {
            curr += (nums[i - 1] == 1) - (nums[i - 1] == 0);
            if (diff.count(curr))
                ans = max(ans, i - diff[curr]);
            else
                diff[curr] = i;
        }
        return ans;
    }
};

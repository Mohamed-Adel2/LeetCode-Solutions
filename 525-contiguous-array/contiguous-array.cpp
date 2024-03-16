class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size(), ans = 0;
        vector<vector<int>> prefix(n + 1, vector<int>(2));
        unordered_map<int, int> diff;
        diff[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i][0] = prefix[i - 1][0] + (nums[i - 1] == 0);
            prefix[i][1] = prefix[i - 1][1] + (nums[i - 1] == 1);
            int curr = prefix[i][0] - prefix[i][1];
            if (diff.count(curr))
                ans = max(ans, i - diff[curr]);
            else
                diff[curr] = i;
        }
        return ans;
    }
};

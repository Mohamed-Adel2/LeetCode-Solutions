class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> freq;
        unordered_map<int, bool> vis;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
            freq[nums[i]] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (freq[nums[i]] == -1 || vis.count(nums[i]))
                continue;
            vis[nums[i]] = true;
            int num = nums[i] + 1;
            int cnt = 1;
            while (freq.count(num) && freq[num] != -1)
                cnt += freq[num], freq[num] = -1, ++num;
            freq[nums[i]] = cnt;
            ans = max(ans, cnt);
        }
        return ans;

    }
};
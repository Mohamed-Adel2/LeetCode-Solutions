class Solution {
public:
    long long countSubarrays(vector<int> &nums, int k) {
        int mx = 0, sz = nums.size();
        long long ans = 0;
        for (int i = 0; i < sz; ++i)
            mx = max(mx, nums[i]);
        vector<int> el;
        for (int i = 0; i < sz; ++i)
            if (nums[i] == mx)
                el.push_back(i);
        int elSz = el.size();
        for (int i = 0; i + k - 1 < elSz; ++i) {
            long long before = (i ? el[i] - el[i - 1] - 1 : el[i]), after = sz - el[i + k - 1] - 1;
            ans += before + after + before * after + 1;
        }
        return ans;
    }
};
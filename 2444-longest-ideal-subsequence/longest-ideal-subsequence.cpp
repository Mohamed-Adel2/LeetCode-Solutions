class Solution {
public:
    int longestIdealString(string s, int k) {
        int sz = s.size();
        vector<int> v(26, 0);
        for (int i = 0; i < sz; ++i) {
            int idx = s[i] - 'a';
            int lower = max(idx - k, 0), upper = min(idx + k, 25);
            v[idx] = v[idx] + 1;
            for (int j = lower; j <= upper; ++j) {
                if (j == idx)
                    continue;
                v[idx] = max(v[idx], v[j] + 1);
            }
        }
        int ans = 1;
        for (auto &i: v)
            ans = max(ans, i);
        return ans;
    }
};
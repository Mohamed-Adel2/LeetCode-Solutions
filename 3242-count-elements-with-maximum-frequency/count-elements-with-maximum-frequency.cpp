class Solution {
public:
    int maxFrequencyElements(vector<int> &nums) {
        unordered_map<int, int> freq;
        int mxFreq = 0, ans = 0;
        for (auto &el: nums)
            freq[el]++, mxFreq = max(mxFreq, freq[el]);
        for (auto &i: freq) {
            if (i.second == mxFreq)
                ans += mxFreq;
        }
        return ans;
    }
};
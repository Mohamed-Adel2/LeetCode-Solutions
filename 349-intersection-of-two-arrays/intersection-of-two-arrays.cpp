class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> freq;
        for (auto &i: nums1)
            freq[i] = 1;
        for (auto &i: nums2)
            if (freq[i] == 1)
                freq[i] = 2;
        vector<int> ans;
        for (auto &el: freq)
            if (el.second == 2)
                ans.push_back(el.first);
        return ans;
    }
};
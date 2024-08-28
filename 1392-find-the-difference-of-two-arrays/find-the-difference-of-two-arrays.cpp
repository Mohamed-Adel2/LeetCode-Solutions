class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1, freq2;
        for(int i = 0; i < nums1.size(); ++i)
            freq1[nums1[i]] = 1;
        for(int i = 0; i < nums2.size(); ++i)
            freq2[nums2[i]] = 1;
        vector<int> ans1, ans2;
        for(int i = 0; i < nums1.size(); ++i)
            if(freq1[nums1[i]] && freq2.count(nums1[i]) == 0)
                ans1.push_back(nums1[i]), --freq1[nums1[i]];
        for(int i = 0; i < nums2.size(); ++i)
            if(freq2[nums2[i]] && freq1.count(nums2[i]) == 0)
                ans2.push_back(nums2[i]), --freq2[nums2[i]];
        vector<vector<int>> v{ans1, ans2};
        return v;
    }
};
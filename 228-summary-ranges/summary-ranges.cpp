class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int start = nums[i];
            int end = nums[i];
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[j - 1] + 1)
                end = nums[j], ++j;
            if (start == end)
                ans.push_back(to_string(nums[i]));
            else
                ans.push_back(to_string(start) + "->" + to_string(end));
            i = j - 1;
        }
        return ans;
    }
};
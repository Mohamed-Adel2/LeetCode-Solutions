class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        unordered_map<int, int> oneFreq, zeroFreq;
        int currSum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i])
                ++zeroFreq[currSum];
            else
                ++oneFreq[++currSum];
            ans += (zeroFreq[currSum - goal] + oneFreq[currSum - (goal - 1)]);
        }
        return ans;
    }
};
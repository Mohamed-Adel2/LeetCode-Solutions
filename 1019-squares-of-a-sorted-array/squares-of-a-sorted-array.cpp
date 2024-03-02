class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int negPtr = 0, posPtr = nums.size() - 1;
        vector<int> ret;
        while (negPtr <= posPtr) {
            if (abs(nums[negPtr]) > abs(nums[posPtr]))
                ret.emplace_back(nums[negPtr] * nums[negPtr++]);
            else
                ret.emplace_back(nums[posPtr] * nums[posPtr--]);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
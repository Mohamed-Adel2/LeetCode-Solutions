class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> pos, neg;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                pos.emplace_back(nums[i]);
            else
                neg.emplace_back(-nums[i]);
        }
        int posPtr = 0, negPtr = neg.size() - 1, numsPtr = 0, posSz = pos.size();
        while (posPtr < posSz && negPtr >= 0) {
            if (pos[posPtr] < neg[negPtr])
                nums[numsPtr++] = pos[posPtr] * pos[posPtr++];
            else
                nums[numsPtr++] = neg[negPtr] * neg[negPtr--];
        }
        while (posPtr < posSz)
            nums[numsPtr++] = pos[posPtr] * pos[posPtr++];
        while (negPtr >= 0)
            nums[numsPtr++] = neg[negPtr] * neg[negPtr--];
        return nums;
    }
};
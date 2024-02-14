class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        vector<int> pos, neg;
        for (auto i: nums) {
            if (i > 0)
                pos.push_back(i);
            else
                neg.push_back(i);
        }
        for (int i = 0; i < nums.size() / 2; ++i)
            nums[2 * i] = pos[i], nums[2 * i + 1] = neg[i];
        return nums;
    }
};
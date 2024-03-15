class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (int &el: nums)
            ans ^= el;
        return ans;
    }
};

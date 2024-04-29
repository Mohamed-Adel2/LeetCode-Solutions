class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorr = 0;
        for(auto &i : nums)
            xorr ^= i;
        int ans = 0;
        int kBits = __builtin_popcount(k), xorBits = __builtin_popcount(xorr);
        ans += kBits - __builtin_popcount(k & xorr);
        ans += xorBits - __builtin_popcount(k & xorr);
        return ans;
    }
};
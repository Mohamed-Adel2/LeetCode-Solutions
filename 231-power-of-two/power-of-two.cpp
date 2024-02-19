class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n != -2147483648 && __builtin_popcount(n) == 1);
    }
};
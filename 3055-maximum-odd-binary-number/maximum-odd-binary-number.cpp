class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zero = 0, one = 0;
        for (auto &c: s) {
            if (c == '0')
                ++zero;
            else
                ++one;
        }
        s[zero + one-- - 1] = '1';
        for (int i = zero + one - 1; i >= 0; --i) {
            if (zero)
                s[i] = '0', --zero;
            else
                s[i] = '1';
        }
        return s;
    }
};
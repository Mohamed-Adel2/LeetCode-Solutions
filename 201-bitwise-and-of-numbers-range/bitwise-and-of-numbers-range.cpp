class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int anding = 0;
        for (int i = 0; i < 31; ++i) {
            int val = 1 << i;
            if ((right - left < val) && (left & val) && (right & val))
                anding += val;
        }
        return anding;
    }
};
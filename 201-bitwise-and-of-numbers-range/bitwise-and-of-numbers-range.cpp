class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int anding = 0;
        for (int i = 0; i < 31; ++i)
            if ((left & (1 << i)) && (right & (1 << i)) && (right - left < (1 << i)))
                anding += (1 << i);
        return anding;
    }
};
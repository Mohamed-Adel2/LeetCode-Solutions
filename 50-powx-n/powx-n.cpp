class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n < 0)
            return (1 / myPow(x, -(n + 1))) * (1 / x);
        double val = myPow(x, n / 2);
        return val * val * (n & 1 ? x : 1);
    }
};
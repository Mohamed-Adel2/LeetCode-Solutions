class Solution {
public:
    int pivotInteger(int n) {
        int lo = 1, hi = n, tot = getSum(n);
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int sum = getSum(mid), sum2 = getSum(mid - 1);
            if (tot - sum2 == sum)
                return mid;
            else if (tot - sum2 < sum)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return -1;
    }

    int getSum(int num) {
        return num * (num + 1) / 2;
    }
};
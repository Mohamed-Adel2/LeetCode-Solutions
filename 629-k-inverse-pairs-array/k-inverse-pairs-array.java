class Solution {
    public int kInversePairs(int n, int k) {
        if (k == 0)
            return 1;
        int prv[] = new int[k + 1];
        prv[0] = 1;
        for (int i = 1; i <= n; i++) {
            int curr[] = new int[k + 1];
            for (int j = 1; j <= k; j++) {
                prv[j] += prv[j - 1];
                prv[j] %= 1000000007;
            }
            for (int j = 0; j <= k; j++) {
                curr[j] = prv[j];
                if (j - (i - 1) - 1 >= 0) {
                    curr[j] -= prv[j - (i - 1) - 1];
                    curr[j] += 1000000007;
                    curr[j] %= 1000000007;
                }
            }
            prv = curr;
        }
        return prv[k];
    }
}
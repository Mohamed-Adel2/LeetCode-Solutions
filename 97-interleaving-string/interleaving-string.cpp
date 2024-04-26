class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n, m, k;

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size(), m = s2.size(), k = s3.size();
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return solve(0, 0, 0, s1, s2, s3);
    }

    int solve(int idx1, int idx2, int idx3, string &s1, string &s2, string &s3) {
        if (idx3 == k)
            return (idx1 == n && idx2 == m);
        int &ret = dp[idx1][idx2][idx3];
        if (~ret)
            return ret;
        ret = 0;
        if (idx1 < n && s1[idx1] == s3[idx3])
            ret |= solve(idx1 + 1, idx2, idx3 + 1, s1, s2, s3);
        if (idx2 < m && s2[idx2] == s3[idx3])
            ret |= solve(idx1, idx2 + 1, idx3 + 1, s1, s2, s3);
        return ret;
    }
};
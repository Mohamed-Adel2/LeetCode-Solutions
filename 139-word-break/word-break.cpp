class Solution {
public:
    int n;
    vector<int> dp;

    bool wordBreak(string s, vector<string> &wordDict) {
        n = s.size();
        dp.resize(n, -1);
        return (solve(0, wordDict, s) > 0);
    }

    int solve(int idx, vector<string> &wordDict, string &s) {
        if (idx >= n)
            return 1;
        int &ret = dp[idx];
        if (~ret)
            return ret;
        ret = 0;
        for (auto &str: wordDict) {
            if (equalStrings(s, str, idx)) {
                ret |= solve(idx + str.size(), wordDict, s);
                if (ret)
                    break;
            }
        }
        return ret;
    }

    bool equalStrings(string &s1, string &s2, int idx) {
        if (s1.size() - idx < s2.size())
            return false;
        for (int i = idx, j = 0; j < s2.size(); ++i, ++j) {
            if (s1[i] != s2[j])
                return false;
        }
        return true;
    }
};
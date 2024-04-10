class Solution {
public:
    vector<vector<int>> dp;
    int sz1, sz2;
    int minDistance(string word1, string word2) {
        sz1 = word1.size(), sz2 = word2.size();
        dp.resize(sz1, vector<int>(sz2, -1));
        return solve(word1, word2, 0, 0);
    }

    int solve(string& word1, string& word2, int idx1, int idx2){
        if(idx1 >= sz1)
            return sz2 - idx2;
        if(idx2 >= sz2)
            return sz1-idx1;
        int& ret = dp[idx1][idx2];
        if(~ret)
            return ret;
        ret = 700;
        if(word1[idx1] == word2[idx2])
            ret = solve(word1, word2, idx1 + 1, idx2 + 1);
        ret = min(ret, solve(word1, word2, idx1, idx2 + 1) + 1);
        ret = min(ret, solve(word1, word2, idx1 + 1, idx2) + 1);
        ret = min(ret, solve(word1, word2, idx1 + 1, idx2 + 1) + 1);
        return ret;
    }
};
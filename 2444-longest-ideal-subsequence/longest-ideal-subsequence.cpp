class Solution {
public:
    vector<vector<int>> dp;
    int sz;
    int longestIdealString(string s, int k) {
        sz = s.size();
        dp.resize(sz + 2, vector<int>(28, -1));
        return solve(0, 27, k, s);
    }

    int solve(int idx, int prv, int k, string& s){
        if(idx >= sz)
            return 0;
        int& ret = dp[idx][prv];
        if(~ret)
            return ret;
        ret = solve(idx+1, prv, k, s);
        if(prv == 27 || abs((s[idx] - 'a') - prv) <= k)
            ret = max(ret, solve(idx+1, s[idx] - 'a', k, s) + 1);
        return ret;
    }

};
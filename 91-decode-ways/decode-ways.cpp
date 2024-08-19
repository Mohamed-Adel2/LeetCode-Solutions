class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 2, -1);
        return solve(0, s, dp);
    }

    int solve(int idx, string& s, vector<int>& dp){
        if(idx >= s.size())
            return 1;
        if (s[idx] == '0')
            return 0;
        int& ret = dp[idx];
        if(~ret)
            return ret;
        ret = solve(idx + 1, s, dp);
        if(idx + 1 < s.size() && s.substr(idx, 2) <= "26")
            ret += solve(idx + 2, s, dp);
        return ret;
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 2, vector<int>(p.size(), -1));
        return solve(s, 0, p, 0, dp);
    }

    int solve(string& s, int sIdx, string& p, int pIdx, vector<vector<int>>& dp){
        if(sIdx == s.size() && pIdx == p.size())
            return 1;
        if(sIdx == s.size()){
            for(int i = pIdx; i < p.size(); ++i)
                if(p[i] != '*')
                    return 0;
            return dp[sIdx][pIdx] = 1;
        }
        if(pIdx == p.size())
            return 0;
        int& ret = dp[sIdx][pIdx];
        if(~ret)
            return ret;
        ret = 0;
        if(s[sIdx] == p[pIdx] || p[pIdx] == '?')
            ret |= solve(s, sIdx + 1, p, pIdx + 1, dp);
        if(p[pIdx] == '*'){
            ret |= solve(s, sIdx + 1, p, pIdx, dp);
            ret |= solve(s, sIdx, p, pIdx + 1, dp);
            ret |= solve(s, sIdx + 1, p, pIdx + 1, dp);
        }
        return ret;
    }


};
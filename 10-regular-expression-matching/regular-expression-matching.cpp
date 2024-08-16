class Solution {
public:
    bool isMatch(string s, string p) {
        vector<string> v = getPSubPatterns(p);
        vector<vector<int>> dp(s.size() + 2, vector<int>(v.size() + 2, -1));
        return solve(s, 0, v, 0,dp);
    }

    vector<string> getPSubPatterns(string& p){
        vector<string> ret;
        for(int i = 0; i < p.size(); ++i){
            string s;
            s+= p[i];
            if(i + 1< p.size() && p[i + 1] == '*')
                s += '*', ++i;
            ret.push_back(s);
        }
        return ret;
    }

    int solve(string& s, int sIdx, vector<string>& p, int pIdx, vector<vector<int>>& dp){
        if(sIdx == s.size() && pIdx == p.size())
            return 1;
        if(sIdx == s.size()){
            for(int i = pIdx; i < p.size(); ++i)
                if(p[i].size() != 2)
                    return 0;
            return dp[sIdx][pIdx] = 1;
        }
        else if(pIdx == p.size())
            return 0;
        int& ret = dp[sIdx][pIdx];
        if(~ret)
            return ret;
        ret = 0;
        if(s[sIdx] == p[pIdx][0] || p[pIdx][0] == '.'){
            ret |= solve(s, sIdx + 1, p, pIdx + 1, dp);
            if(p[pIdx].size() == 2)
                ret |= solve(s, sIdx + 1, p, pIdx, dp);
        }
        if(p[pIdx].size() == 2)
            ret |= solve(s, sIdx, p, pIdx + 1, dp);
        return ret;
    }
};
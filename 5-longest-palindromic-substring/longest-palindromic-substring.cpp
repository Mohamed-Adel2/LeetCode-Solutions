class Solution {
public:
    string s;
    string fi, se;
    int dp[1001][1001];
    string longestPalindrome(string ss) {
        s = ss;
        memset(dp,-1, sizeof(dp));
        solve(0, ss.size()-1);
        build(0, ss.size()-1);
        reverse(se.begin(), se.end());
        return fi+se;

    }
    int solve(int idx1, int idx2){
        if(idx1>=idx2)
            return idx1==idx2;
        int& ret = dp[idx1][idx2];
        if(~ret)
            return ret;
        ret = 0;
        if(s[idx1]==s[idx2]){
            ret = solve(idx1+1, idx2-1);
            if(ret == idx2 - idx1 - 1)
                ret+=2;
        }
        ret = max(ret, solve(idx1, idx2-1));
        ret = max(ret, solve(idx1+1, idx2));
        return ret;
    }

     void build(int idx1, int idx2){
        if(idx1>idx2)
            return;
        if(idx1==idx2){
            fi+=s[idx1];
            return;
        }
        int& ret = dp[idx1][idx2];
        if(ret == solve(idx1+1, idx2-1)+2 && solve(idx1+1, idx2-1) == idx2 - idx1 - 1){
            fi+=s[idx1];
            se+=s[idx2];
            build(idx1+1, idx2-1);
        }
        else if(ret == solve(idx1+1, idx2-1)){
            build(idx1+1, idx2-1);
        }
        else if(ret == solve(idx1, idx2-1))
            build(idx1, idx2-1);
        else
            build(idx1+1, idx2);
    }


};
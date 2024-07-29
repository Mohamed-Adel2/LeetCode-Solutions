class Solution {
public:
    int dp[1002][1002][4][2];
    //vector<vector<vector<vector<int>>>> dp;
    int numTeams(vector<int>& rating) {
        int sz = rating.size();
        //dp.resize(sz + 2, vector<int>(sz , vector<int>(4, vector<int>(2, -1))));
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, true, rating, sz);
    }

    int solve(int curr, int last, int cnt, bool inc, vector<int>& rating, int sz){
        if(cnt == 3)
            return 1;
        if(curr >= sz)
            return 0;
        int& ret = dp[curr][last][cnt][inc];
        if(~ret)
            return ret;
        ret = solve(curr + 1, last, cnt, inc, rating, sz);
        if(cnt == 0)
            ret += solve(curr + 1, curr, cnt + 1, true, rating, sz) + solve(curr + 1, curr, cnt + 1, false, rating, sz);
        else if((inc && rating[curr] > rating[last]) || (!inc && rating[curr] < rating[last]))
            ret += solve(curr + 1, curr, cnt + 1, inc, rating, sz);
        return ret;
    }
};
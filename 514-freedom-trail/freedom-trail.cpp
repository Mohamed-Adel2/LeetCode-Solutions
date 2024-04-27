class Solution {
public:
    vector<vector<int>> dp, pos;
    int n, m;
    int findRotateSteps(string ring, string key) {
        n = ring.size(), m = key.size();
        pos.resize(26), dp.resize(n + 1, vector<int>(m + 1, -1));
        for(int i = 0; i < n; ++i)
            pos[ring[i] - 'a'].push_back(i);
        return solve(0, 0, key);
    }

    int solve(int ringIdx, int keyIdx, string& key){
        if(keyIdx == m)
            return 0;
        int &ret = dp[ringIdx][keyIdx];
        if(~ret)    
            return ret;
        ret = 1e9;
        int nxtChar = key[keyIdx] - 'a';
        for(int i = 0; i < pos[nxtChar].size(); ++i){
            int distance = min(abs(ringIdx - pos[nxtChar][i]), n - abs(ringIdx - pos[nxtChar][i]));
            ret = min(ret, solve(pos[nxtChar][i], keyIdx + 1, key) + distance + 1);
        }
        return ret;
    }
};
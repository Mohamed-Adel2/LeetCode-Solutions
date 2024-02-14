class Solution {
public:
    int numberOfBeams(vector<string> &bank) {
        int prvCnt = 0, ans = 0;
        for (int i = 0; i < bank.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < bank[i].size(); ++j)
                cnt += (bank[i][j] == '1');
            if (cnt > 0)
                ans += cnt * prvCnt, prvCnt = cnt;
        }
        return ans;
    }
};
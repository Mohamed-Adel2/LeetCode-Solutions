class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust) {
        vector<vector<int>> freq(n + 1, vector<int>(2));
        for (int i = 0; i < trust.size(); ++i)
            ++freq[trust[i][0]][0], ++freq[trust[i][1]][1];
        for (int i = 1; i <= n; ++i)
            if (freq[i][0] == 0 && freq[i][1] == n - 1)
                return i;
        return -1;
    }
};
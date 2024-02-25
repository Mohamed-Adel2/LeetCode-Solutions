class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        queue<pair<int, int>> q;
        vector<bool> vis(bank.size());
        q.push({-1, 0});
        while (!q.empty()) {
            int idx = q.front().first;
            int mutations = q.front().second;
            string currGene = (idx != -1 ? bank[idx] : startGene);
            q.pop();
            if (currGene == endGene)
                return mutations;
            for (int i = 0; i < bank.size(); ++i) {
                if (!vis[i] && onlyOneDifference(currGene, bank[i])) {
                    q.push({i, mutations + 1}), vis[i] = true;
                }
            }
        }
        return -1;
    }

    bool onlyOneDifference(string &s1, string &s2) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            if (s1[i] != s2[i]) {
                ++cnt;
                if (cnt == 2)
                    break;
            }
        }
        return cnt == 1;
    }
};
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        queue<pair<string, int>> q;
        vector<bool> vis(bank.size());
        q.push({startGene, 0});
        while (!q.empty()) {
            string currGene = q.front().first;
            int mutations = q.front().second;
            q.pop();
            if (currGene == endGene)
                return mutations;
            for (int i = 0; i < bank.size(); ++i) {
                if (!vis[i] && onlyOneDifference(currGene, bank[i])) {
                    q.push({bank[i], mutations + 1}), vis[i] = true;
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
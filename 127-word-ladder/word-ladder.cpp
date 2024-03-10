class Solution {
public:
    int ladderLength(string start, string end, vector<string> &list) {
        queue<pair<string, int>> q;
        vector<bool> vis(list.size());
        q.push({start, 0});
        while (!q.empty()) {
            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (curr == end)
                return dist + 1;
            for (int i = 0; i < list.size(); ++i) {
                if (!vis[i] && differByOne(curr, list[i]))
                    vis[i] = true, q.push({list[i], dist + 1});
            }
        }
        return 0;
    }

    bool differByOne(string &s1, string &s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++cnt;
                if (cnt == 2)
                    return false;
            }
        }
        return true;
    }
};
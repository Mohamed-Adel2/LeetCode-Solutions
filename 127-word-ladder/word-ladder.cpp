class Solution {
public:
    int ladderLength(string start, string end, vector<string> &list) {
        queue<pair<string, int>> q;
        unordered_map<string, bool> freq;
        for (auto &el: list)
            freq[el] = true;
        for (int i = 0; i < list.size(); ++i)
            freq[list[i]] = true;
        vector<bool> vis(list.size());
        q.push({start, 0});
        while (!q.empty()) {
            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (curr == end)
                return dist + 1;
            for (int i = 0; i < curr.size(); ++i) {
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch == curr[i])
                        continue;
                    char tmp = curr[i];
                    curr[i] = ch;
                    if (freq.find(curr) != freq.end())
                        q.push({curr, dist + 1}), freq.erase(curr);
                    curr[i] = tmp;
                }
            }
        }
        return 0;
    }
};
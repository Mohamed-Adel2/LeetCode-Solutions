class Solution {
public:
    int ladderLength(string start, string end, vector<string> &list) {
        queue<pair<string, int>> q;
        unordered_set<string> freq(list.begin(), list.end());
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
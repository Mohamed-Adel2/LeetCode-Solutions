class Solution {
public:
    int ladderLength(string start, string end, vector<string> &list) {
        queue<pair<string, int>> q;
        unordered_map<string, bool> freq;
        for (auto &el: list)
            freq[el] = true;
        q.push({start, 0});
        while (!q.empty()) {
            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (curr == end)
                return dist + 1;
            for (int i = 0; i < curr.size(); ++i) {
                vector<string> marked;
                for (auto &el: freq) {
                    if (differByOne(curr, el.first))
                        q.push({el.first, dist + 1}), marked.push_back(el.first);
                }
                for (auto &el: marked)
                    freq.erase(el);
            }
        }
        return 0;
    }

    bool differByOne(const string &s1, const string &s2) {
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
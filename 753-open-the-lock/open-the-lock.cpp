class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        queue<string> q;
        unordered_map<string, int> visited;
        for (auto &s: deadends)
            visited[s] = 1;
            if(visited["0000"])
                return -1;
        q.push("0000"), visited["0000"] = 0;
        while (!q.empty()) {
            string curr = q.front();
            int steps = visited[curr];
            if(curr == target)
                break;
            q.pop();
            vector<string> nexts = next(curr);
            for (auto &s: nexts) {
                if (!visited[s])
                    q.push(s), visited[s] = steps + 1;
            }
        }
        return (visited.count(target) ? visited[target] : -1);
    }

    vector<string> next(string &s) {
        vector<string> next;
        for (int i = 0; i < 4; ++i) {
            char tmp = s[i];
            s[i] = (tmp == '0' ? '9' : tmp - 1);
            next.push_back(s);
            s[i] = (tmp == '9' ? '9' : tmp + 1);
            next.push_back(s);
            s[i] = tmp;
        }
        return next;
    }
};
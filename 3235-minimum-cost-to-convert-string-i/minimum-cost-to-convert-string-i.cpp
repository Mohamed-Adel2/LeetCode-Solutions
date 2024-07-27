class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> d;

    long long
    minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost) {
        adj.resize(26, vector<int>(26, 1e9));
        d.resize(26, vector<int>(26, 1e9));
        for (int i = 0; i < original.size(); ++i)
            adj[original[i] - 'a'][changed[i] - 'a'] = min(cost[i], adj[original[i] - 'a'][changed[i] - 'a']);
        for (int i = 0; i < 26; ++i)
            dijkstra(i);
        long long ans = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i])
                continue;
            int ret = d[source[i] - 'a'][target[i] - 'a'];
            if (ret == 1e9)
                return -1;
            ans += ret;
        }
        return ans;
    }

    void dijkstra(int src) {
        d[src][src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src});
        while (!q.empty()) {
            pair<int, int> top = q.top();
            q.pop();
            if (d[src][top.second] != top.first)
                continue;
            for (int i = 0; i < 26; ++i)
                if (adj[top.second][i] != 1e9 && adj[top.second][i] + d[src][top.second] < d[src][i]) {
                    d[src][i] = d[src][top.second] + adj[top.second][i];
                    q.push({d[src][i], i});
                }
        }
    }
};

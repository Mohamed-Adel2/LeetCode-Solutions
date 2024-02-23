class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    int ans = INT32_MAX;
    vector<int> vis;

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        adj.resize(n);
        vis.resize(n, INT32_MAX);
        for (int i = 0; i < flights.size(); ++i)
            adj[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
        bfs(src, dst, k);
        return (ans == INT32_MAX ? -1 : ans);
    }

    void bfs(int src, int dist, int k) {
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            int cost = q.front().first, node = q.front().second.first, steps = q.front().second.second;
            q.pop();
            if (steps > k + 1)
                break;
            vis[node] = cost;
            if (node == dist) {
                ans = min(cost, ans);
                continue;
            }
            for (auto i: adj[node]) {
                int to = i.first, price = i.second;
                if (vis[to] > cost + price)
                    q.push({cost + price, {to, steps + 1}});
            }
        }
    }
};
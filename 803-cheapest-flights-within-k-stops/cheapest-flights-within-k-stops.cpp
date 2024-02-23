class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    int ans = INT32_MAX;
    vector<vector<bool>> vis;

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        adj.resize(n);
        vis.resize(n, vector<bool>(k + 2));
        for (int i = 0; i < flights.size(); ++i)
            adj[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
        dijkstra(src, dst, k);
        return (ans == INT32_MAX ? -1 : ans);
    }

    void dijkstra(int src, int dist, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            int cost = q.top().first, node = q.top().second.first, steps = q.top().second.second;
            q.pop();
            if (vis[node][steps])
                continue;
            vis[node][steps] = true;
            if (node == dist) {
                ans = min(cost, ans);
                continue;
            }
            if (steps == k + 1)
                continue;
            for (auto i: adj[node]) {
                int to = i.first, price = i.second;
                if (!vis[to][steps + 1] && steps <= k)
                    q.push({cost + price, {to, steps + 1}});
            }
        }
    }
};

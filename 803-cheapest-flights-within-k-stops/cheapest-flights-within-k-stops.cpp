class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dis(n, INT32_MAX);
        int ans = INT32_MAX;
        for (int i = 0; i < flights.size(); ++i)
            adj[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            int cost = q.front().first, node = q.front().second.first, steps = q.front().second.second;
            q.pop();
            dis[node] = cost;
            if (steps > k + 1)
                break;
            if (node == dst) {
                ans = min(cost, ans);
                continue;
            }
            for (auto i: adj[node]) {
                int to = i.first, price = i.second;
                if (dis[to] > cost + price)
                    q.push({cost + price, {to, steps + 1}});
            }
        }
        return (ans == INT32_MAX ? -1 : ans);
    }
};
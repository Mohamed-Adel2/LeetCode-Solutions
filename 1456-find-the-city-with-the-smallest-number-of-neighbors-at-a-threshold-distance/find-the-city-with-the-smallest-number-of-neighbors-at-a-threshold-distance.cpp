class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        adj.resize(n);
        for(int i = 0; i < edges.size();++i){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int ans = n + 3;
        int node = -1;
        for(int i = 0; i < n; ++i){
            int ret = dijkstra(i, n, distanceThreshold);
            if(ret <= ans)
                node = i, ans = ret;
        }
        return node;
    }

    int dijkstra(int src, int n, int distanceThreshold) {
        int ret = 0;
        vector<int> d(n, 1e9);
        d[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src});
        while (!q.empty()) {
            pair<int, int> top = q.top();
            q.pop();
            if (d[top.second] != top.first)
                continue;
            ++ret;
            for(auto &i : adj[top.second]){
                if(d[i.first] > d[top.second] + i.second && d[top.second] + i.second <= distanceThreshold){
                    d[i.first] = d[top.second] + i.second;
                    q.push({d[i.first], i.first});
                }
            }   
        }
        return ret;
    }
};
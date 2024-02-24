class Solution {
public:
    vector<int> ans;

    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < meetings.size(); ++i){
            adj[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            adj[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }
        dijkstra(firstPerson, n, adj);
        return ans;
    }

    void dijkstra(int start, int n, vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, start});
        q.push({0, 0});
        vector<bool> vis(n);
        while (!q.empty()) {
            int node = q.top().second, time = q.top().first;
            q.pop();
            if (vis[node])
                continue;
            ans.push_back(node);
            vis[node] = true;
            for (auto i: adj[node]) {
                if (i.second >= time)
                    q.push({i.second, i.first});
            }
        }
    }
};
class Solution {
public:
    double ans = -1.0;

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        map<string, int> mp;
        vector<vector<pair<int, double>>> adj(26);
        int curr = 0;
        for (int i = 0; i < equations.size(); ++i) {
            if (!mp.count(equations[i][0]))
                mp[equations[i][0]] = curr++;
            if (!mp.count(equations[i][1]))
                mp[equations[i][1]] = curr++;
            adj[mp[equations[i][0]]].emplace_back(mp[equations[i][1]], values[i]);
            adj[mp[equations[i][1]]].emplace_back(mp[equations[i][0]], 1.0 / values[i]);
        }
        vector<double> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            vector<bool> vis(curr);
            if (mp.count(queries[i][0]) && mp.count(queries[i][1]))
                dfs(mp[queries[i][0]], mp[queries[i][1]], adj, vis, 1);
            ret[i] = ans;
            ans = -1;
        }
        return ret;
    }

    void dfs(int node, int end, vector<vector<pair<int, double>>> &adj, vector<bool> &vis, double val) {
        if (node == end) {
            ans = val;
            return;
        }
        vis[node] = true;
        for (auto &i: adj[node]) {
            if (vis[i.first])
                continue;
            dfs(i.first, end, adj, vis, val * i.second);
            if (ans != -1)
                return;
        }
    }
};

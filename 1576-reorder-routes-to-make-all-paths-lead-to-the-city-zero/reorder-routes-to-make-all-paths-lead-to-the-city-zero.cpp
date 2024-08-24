class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < connections.size(); ++i){
            adj[connections[i][0]].push_back({connections[i][1], 1});
            adj[connections[i][1]].push_back({connections[i][0], 0});
        }
        int ans = 0;
        dfs(0, -1, ans, adj);
        return ans;
    }

    void dfs(int node, int par, int& ans, vector<vector<pair<int, int>>>& adj){
        for(auto &i : adj[node])
            if(i.first != par)
                ans += i.second, dfs(i.first, node, ans, adj);
    }
};
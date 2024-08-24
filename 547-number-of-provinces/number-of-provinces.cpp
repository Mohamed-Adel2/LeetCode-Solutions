class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(i != j && isConnected[i][j] == 1)
                    adj[i].push_back(j);
        vector<bool> vis(n);
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(!vis[i])
                dfs(i, vis, adj), ++ans;
        return ans;
    }

    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj){
        vis[node] = true;
        for(auto &i : adj[node])
            if(!vis[i])
                dfs(i, vis, adj);
    }
};
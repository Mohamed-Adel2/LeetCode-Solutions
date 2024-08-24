class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < rooms[i].size(); ++j)
                if(rooms[i][j] != i)
                    adj[i + 1].push_back(rooms[i][j] + 1);
        vector<bool> vis(n + 1);
        dfs(1, vis, adj);
        for(int i = 1; i <= n; ++i)
            if(!vis[i])
                return false;
        return true;
    }

    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj){
        vis[node] = true;
        for(auto &i : adj[node])
            if(!vis[i])
                dfs(i, vis, adj);
    }
};
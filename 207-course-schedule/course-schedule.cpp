class Solution {
public:
    bool valid = true;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i)
            adj[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        for (int i = 0; i < numCourses; ++i)
            if (!vis[i])
                dfs(i, adj, vis);
        return valid;
    }

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 2;
        for (auto &i: adj[node]) {
            if (!valid)
                return;
            if (vis[i] == 2) {
                valid = false;
                return;
            } else if (vis[i])
                continue;
            dfs(i, adj, vis);
        }
        --vis[node];
    }
};
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> ans;
        vector<int> curr{0};
        solve(ans, graph, curr, 0, graph.size() - 1);
        return ans;
    }

    void solve(vector<vector<int>> &ans, vector<vector<int>> &adj, vector<int> &curr, int node, int n) {
        if (node == n)
            return void(ans.push_back(curr));
        for (auto &i: adj[node]) {
            curr.push_back(i);
            solve(ans, adj, curr, i, n);
            curr.pop_back();
        }
    }
};
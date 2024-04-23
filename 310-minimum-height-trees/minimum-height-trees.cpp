class Solution {
public:
    vector<pair<int, int>> firstMax, secondMax;
    vector<vector<int>> adj;
    vector<int> h;
    int mn = 1e9;

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if(n == 1)
            return {0};
        firstMax.resize(n), secondMax.resize(n), adj.resize(n), h.resize(n);
        for (int i = 0; i < n - 1; ++i)
            adj[edges[i][0]].push_back(edges[i][1]), adj[edges[i][1]].push_back(edges[i][0]);
        pre(0, 0);
        solve(0, 0, -1);
        vector<int> ret;
        for (int i = 0; i < n; ++i)
            if (h[i] == mn)
                ret.push_back(i);
        return ret;
    }

    void pre(int node, int par) {
        for (auto &i: adj[node]) {
            if (i == par)
                continue;
            pre(i, node);
            if (firstMax[i].second + 1 > firstMax[node].second) {
                secondMax[node] = firstMax[node];
                firstMax[node].first = i, firstMax[node].second = firstMax[i].second + 1;
            } else if (firstMax[i].second + 1 > secondMax[node].second)
                secondMax[node].first = i, secondMax[node].second = firstMax[i].second + 1;
        }
    }

    void solve(int node, int par, int maxFromParent) {
        h[node] = max(maxFromParent + 1, firstMax[node].second);
        mn = min(mn, h[node]);
        for (auto &i: adj[node]) {
            if (i == par)
                continue;
            if (i == firstMax[node].first)
                solve(i, node, max(secondMax[node].second, maxFromParent + 1));
            else
                solve(i, node, max(firstMax[node].second, maxFromParent + 1));
        }
    }
};
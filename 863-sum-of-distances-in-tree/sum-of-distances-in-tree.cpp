class Solution {
public:
    vector<int> sz, ans;
    vector<vector<int>> adj;
    int dist = 0, nodeCnt = 0;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        sz.resize(n), adj.resize(n), ans.resize(n);
        for(int i = 0; i < edges.size(); ++i)
            adj[edges[i][0]].push_back(edges[i][1]), adj[edges[i][1]].push_back(edges[i][0]);
        pre(0, -1, 0);
        ans[0] = dist;
        solve(0, -1);
        return ans;
    }

    int pre(int node, int par, int depth){
        dist += depth, ++nodeCnt, sz[node] = 1;
        for(auto &i : adj[node]){
            if(i == par)
                continue;
            sz[node] += pre(i, node, depth + 1);
        }
        return sz[node];
    }

    void solve(int node, int par){
        if(node)
            ans[node] = ans[par] - sz[node] + (nodeCnt - sz[node]);
        for(auto &i : adj[node]){
            if(i == par)
                continue;
            solve(i, node);
        }
    }
};
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> indegree;

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1)
            return {0};
        indegree.resize(n), adj.resize(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[edges[i][0]].push_back(edges[i][1]), adj[edges[i][1]].push_back(edges[i][0]);
            ++indegree[edges[i][0]], ++indegree[edges[i][1]];
        }
        deque<int> q;
        vector<int> ret;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 1)
                q.push_back(i);
        int consumed = 0;
        while (consumed < n - 2) {
            int sz = q.size();
            for (int j = 0; j < sz; ++j) {
                for (auto &i: adj[q.front()]) {
                    --indegree[i];
                    if (indegree[i] == 1)
                        q.push_back(i);
                }
                q.pop_front();
                ++consumed;
            }
        }
        while (!q.empty())
            ret.push_back(q.back()), q.pop_back();
        return ret;
    }
};
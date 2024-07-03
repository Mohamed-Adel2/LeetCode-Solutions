class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> tmpAns(n);
        vector<vector<int>> ans(n);
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            ++indegree[edge[1]];
            adj[edge[0]].push_back(edge[1]);
        }
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(indegree[i] == 0)
                q.push(i);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto& node : adj[top]){
                tmpAns[node].insert(top);
                for(auto &i : tmpAns[top])
                    tmpAns[node].insert(i);
                if(--indegree[node] == 0)
                    q.push(node);
            }
        }
        for(int i = 0; i < n; ++i)
            for(auto& num : tmpAns[i])
                ans[i].push_back(num);
        return ans;
    }
};
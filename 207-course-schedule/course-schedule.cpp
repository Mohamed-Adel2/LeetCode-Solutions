class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i)
            adj[prerequisites[i][1]].emplace_back(prerequisites[i][0]), ++inDegree[prerequisites[i][0]];
        return topologicalSort(numCourses, inDegree, adj);
    }

    bool topologicalSort(int &numCourses, vector<int> &inDegree, vector<vector<int>> &adj) {
        queue<int> topSort;
        for (int i = 0; i < numCourses; ++i)
            if (!inDegree[i])
                topSort.push(i);
        int done = 0;
        while (!topSort.empty()) {
            int node = topSort.front();
            topSort.pop(), ++done;
            for (auto &i: adj[node]) {
                --inDegree[i];
                if (!inDegree[i])
                    topSort.push(i);
            }
        }
        return done == numCourses;
    }
};

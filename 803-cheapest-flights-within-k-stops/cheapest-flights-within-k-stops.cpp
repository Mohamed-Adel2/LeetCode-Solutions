class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<int> dis(n, 5e8);
        vector<int> tmp;
        dis[src] = 0;
        for (int i = 0; i <= k; ++i) {
            tmp = dis;
            for (auto &edge: flights)
                tmp[edge[1]] = min(tmp[edge[1]], dis[edge[0]] + edge[2]);
            dis = tmp;
        }
        return (dis[dst] == 5e8 ? -1 : dis[dst]);
    }
};
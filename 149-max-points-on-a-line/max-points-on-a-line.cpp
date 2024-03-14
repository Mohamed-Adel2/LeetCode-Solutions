class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> freq;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][1] == points[j][1])
                    ++freq[100000];
                else {
                    ++freq[(double)(points[i][0] - points[j][0]) / (points[i][1] - points[j][1])];
                }
            }
            for (auto i: freq)
                ans = max(ans, i.second);
        }
        return ans + 1;
    }
};
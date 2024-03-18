class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            ++ans;
            int mnEnd = points[i][1], j = i + 1;
            while (j < points.size() && points[j][0] <= mnEnd)
                mnEnd = min(mnEnd, points[j][1]), ++j;
            i = j - 1;
        }
        return ans;
    }
};
class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        multiset<int> ms;
        int n = heights.size(), ans = 0, bricksSum = 0;
        for (int i = 1; i < n; ++i) {
            if (heights[i] - heights[i - 1] >= 0) {
                ms.insert(heights[i] - heights[i - 1]);
                if (ms.size() > ladders)
                    bricksSum += *ms.begin(), ms.erase(ms.begin());
                if (bricksSum > bricks)
                    break;
            }
            ans = i;
        }
        return ans;
    }
};

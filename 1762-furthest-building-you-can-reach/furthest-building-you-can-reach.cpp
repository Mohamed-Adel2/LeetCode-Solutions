class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> ms;
        int n = heights.size(), ans = 0, bricksSum = 0;
        for (int i = 1; i < n; ++i) {
            if (heights[i] - heights[i - 1] >= 0) {
                ms.push(heights[i] - heights[i - 1]);
                if (ms.size() > ladders)
                    bricksSum += ms.top(), ms.pop();
                if (bricksSum > bricks)
                    break;
            }
            ans = i;
        }
        return ans;
    }
};
class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        int n = heights.size();
        int lo = 0, hi = n - 1, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<int> diff;
            for (int i = 1; i <= mid; i++)
                if (heights[i] - heights[i - 1] > 0)
                    diff.push_back(heights[i] - heights[i - 1]);
            if (valid(diff, bricks, ladders))
                ans = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        return ans;
    }

    bool valid(vector<int> &diff, int bricks, int ladders) {
        sort(diff.begin(), diff.end());
        while (!diff.empty()) {
            if (ladders)
                --ladders, diff.pop_back();
            else {
                if (diff.back() > bricks)
                    return false;
                bricks -= diff.back();
                diff.pop_back();
            }
        }
        return true;
    }
};
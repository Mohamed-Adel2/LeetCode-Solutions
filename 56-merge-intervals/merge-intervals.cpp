class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], mxEnd = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= mxEnd)
                mxEnd = max(mxEnd, intervals[i][1]);
            else
                ans.push_back({start, mxEnd}), start = intervals[i][0], mxEnd = intervals[i][1];
        }
        ans.push_back({start, mxEnd});
        return ans;
    }
};
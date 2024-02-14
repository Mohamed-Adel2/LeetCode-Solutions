class Solution {
public:
    vector<int> dp;
    vector<pair<pair<int, int>, int>> jobs;
    int n;

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        n = startTime.size();
        jobs.resize(n);
        for (int i = 0; i < n; ++i)
            jobs[i] = {{startTime[i], endTime[i]}, profit[i]};
        sort(jobs.begin(), jobs.end());
        dp.resize(n + 2, -1);
        return solve(0);
    }

    int solve(int idx) {
        if (idx >= n)
            return 0;
        int &ret = dp[idx];
        if (~ret)
            return ret;
        int nextIdx = binarySearch(jobs[idx].first.second, idx);
        ret = solve(nextIdx) + jobs[idx].second;
        ret = max(ret, solve(idx + 1));
        return ret;
    }

    int binarySearch(int &key, int &lo) {
        int l = lo + 1, r = jobs.size() - 1;
        int ans = jobs.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (jobs[mid].first.first >= key)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};
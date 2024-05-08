class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> v(n);
        for(int i = 0;i<n;++i)
            v.emplace_back(score[i], i);
        sort(v.rbegin(), v.rend());
        vector<string> ans(n);
        ans[v[0].second] = "Gold Medal";
        if(n < 2)
            return ans;
        ans[v[1].second] = "Silver Medal";
        if(n < 3)
            return ans;
        ans[v[2].second] = "Bronze Medal";
        for(int i = 3; i < n; ++i)
            ans[v[i].second] = to_string(i + 1);
        return ans;
    }
};
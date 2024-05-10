class Solution {
public:
    static bool compare(const pair<int, int> &a, const pair<int, int> &b) {
        return (a.first < b.first) || (a.first == b.first && a.second > b.second);
    }

    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int n = profits.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {capital[i], profits[i]};
        }
        sort(v.begin(), v.end(), compare);
        int curr = w, idx = 0;
        multiset<int> available;
        for (; idx < n; ++idx) {
            if (v[idx].first <= curr)
                available.insert(v[idx].second);
            else
                break;
        }
        while (k-- && !available.empty()) {
            curr += *available.rbegin();
            available.erase(--available.end());
            for (; idx < n; ++idx) {
                if (v[idx].first <= curr)
                    available.insert(v[idx].second);
                else
                    break;
            }
        }
        return curr;
    }
};
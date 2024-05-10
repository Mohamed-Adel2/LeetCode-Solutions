class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int n = profits.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) 
            v[i] = {capital[i], profits[i]};
        sort(v.begin(), v.end());
        int curr = w, idx = 0;
        priority_queue<int> available;
        for (; idx < n; ++idx) {
            if (v[idx].first <= curr)
                available.push(v[idx].second);
            else
                break;
        }
        while (k-- && !available.empty()) {
            curr += available.top();
            available.pop();
            for (; idx < n; ++idx) {
                if (v[idx].first <= curr)
                    available.push(v[idx].second);
                else
                    break;
            }
        }
        return curr;
    }
};
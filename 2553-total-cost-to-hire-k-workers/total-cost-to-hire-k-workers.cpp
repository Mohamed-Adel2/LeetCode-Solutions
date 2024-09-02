class Solution {
public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        set<pair<int, int>> st;
        int left = 0, right = costs.size() - 1;
        for (int i = 0; i < candidates && left <= right; ++i) {
            st.insert({costs[left], left++});
            if (left <= right) {
                st.insert({costs[right], right});
                --right;
            }
        }
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            pair<int, int> pr = *st.begin();
            ans += pr.first;
            int idx = pr.second;
            st.erase(st.begin());
            if (left <= right) {
                if (idx < left)
                    st.insert({costs[left], left++});
                else if (idx > right)
                    st.insert({costs[right], right--});
            }
        }
        return ans;
    }
};
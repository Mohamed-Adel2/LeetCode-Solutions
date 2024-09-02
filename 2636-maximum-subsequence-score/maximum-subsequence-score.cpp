class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        int sz = nums1.size();
        for(int i = 0; i < sz; ++i)
            v.push_back({nums2[i], nums1[i]});
        sort(v.rbegin(), v.rend());
        set<pair<int, int>> st;
        long long sum = 0, ans = 0;
        for(int i = 0; i < k; ++i){
            sum += v[i].second;
            st.insert({v[i].second, v[i].first});
        }
        ans = sum * v[k - 1].first;
        for(int i = k; i < sz; ++i){
            pair<int, int> pr = *st.begin();
            if(v[i].second > pr.first){
                sum = sum - pr.first + v[i].second;
                ans = max(ans, sum * v[i].first);
                st.erase(st.begin());
                st.insert({v[i].second, v[i].first});
            }
        }
        return ans;
    }
};
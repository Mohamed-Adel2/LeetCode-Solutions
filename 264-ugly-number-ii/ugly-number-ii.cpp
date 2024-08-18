class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st{1};
        vector<long long> v;
        while(v.size() < n){
            long long mn = *st.begin();
            st.erase(st.begin());
            v.push_back(mn);
            st.insert(mn * 2), st.insert(mn * 3), st.insert(mn * 5);
        }
        return v[n - 1];
    }
};
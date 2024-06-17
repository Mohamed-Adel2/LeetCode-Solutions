class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> st;
        for(int i = 0; i <= nums.back() * 2 + 2; ++i)
            st.insert(i);
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            auto it = st.lower_bound(nums[i]);
            ans += *it - nums[i];
            st.erase(it);
        }
        return ans;
    }
};
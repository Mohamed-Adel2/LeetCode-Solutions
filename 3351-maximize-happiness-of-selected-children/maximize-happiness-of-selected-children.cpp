class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long int ans= 0;
        for(int i = 0; i < k; ++i)
            ans += max(happiness[i] - i, 0);
        return ans;
    }
};
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        long long int ans= 0;
        for(int i = 0; i < k; ++i)
            ans += max(happiness[n - i - 1] - i, 0);
        return ans;
    }
};
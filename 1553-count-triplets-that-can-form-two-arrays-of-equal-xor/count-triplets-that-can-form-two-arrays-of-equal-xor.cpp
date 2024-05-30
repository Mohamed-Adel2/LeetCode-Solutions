class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        vector<int> prefix(n + 1);
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
            ++freq[prefix[i + 1]];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            --freq[prefix[i + 1]];
            unordered_map<int, int> tmpFreq = freq;
            vector<int> tmpPrefix = prefix;
            for (int j = i + 1; j < n; ++j) {
                ans += tmpFreq[tmpPrefix[i]];
                --tmpFreq[tmpPrefix[j + 1]];
            }
        }
        return ans;
    }
};
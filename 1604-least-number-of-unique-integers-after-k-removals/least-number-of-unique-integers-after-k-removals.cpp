class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        unordered_map<int, int> numFreq;
        vector<int> freq(1e5 + 2);
        int dist = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int &fr = numFreq[arr[i]];
            if (!fr)
                ++dist;
            --freq[fr];
            ++fr;
            ++freq[fr];
        }
        for (int i = 1; i < freq.size(); ++i) {
            if (k < i)
                break;
            dist -= min(k / i, freq[i]);
            k -= min(i * freq[i], k);
        }
        return dist;
    }
};
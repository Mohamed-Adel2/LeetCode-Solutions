class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        unordered_map<int, int> numFreq;
        for (auto &i: arr)
            ++numFreq[i];
        vector<int> freq;
        for (auto &i: numFreq)
            freq.push_back(i.second);
        int dist = freq.size();
        sort(freq.begin(), freq.end());
        for (int i = 0; i < freq.size(); ++i) {
            if (k < freq[i])
                break;
            --dist;
            k -= freq[i];
        }
        return dist;
    }
};
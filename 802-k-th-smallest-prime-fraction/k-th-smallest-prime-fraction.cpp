class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        multiset<pair<double, pair<int, int>>> ms;
        for (int i = 0; i < arr.size(); ++i)
            ms.insert({(double) arr[0] / arr[i], {0, i}});
        while (--k) {
            pair<int, int> idx = (*ms.begin()).second;
            ms.erase(ms.begin());
            if (idx.first < idx.second)
                ms.insert({(double) arr[idx.first + 1] / arr[idx.second], {idx.first + 1, idx.second}});
        }
        vector<int> ans{arr[(*ms.begin()).second.first], arr[(*ms.begin()).second.second]};
        return ans;
    }
};
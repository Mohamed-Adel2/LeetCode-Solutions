class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        if(a.first < b.first)
            return true;
        if(a.first == b.first && a.second > b.second)
            return true;
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto &i : nums)
            freq[i]++;
        vector<pair<int, int>> v;
        for(auto &i : freq)
            v.push_back({i.second, i.first});
        sort(v.begin(), v.end(), compare);
        vector<int> ans;
        for(int i = 0; i < v.size(); ++i)
            for(int j = 0;j < v[i].first; ++j)
                ans.push_back(v[i].second);
        return ans;
    }
};
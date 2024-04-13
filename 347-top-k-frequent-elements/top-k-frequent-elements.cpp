class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> freq(nums.size() + 1);
        for(auto &x:nums)
            ++mp[x];
        for(auto &entry:mp)
            ++freq[entry.second];
        int mn;
        for(int i = freq.size() - 1;i >= 1;--i){
            k -= freq[i];
            if(k == 0){
                mn = i;
                break;
            } 
        }
        vector<int> ans;
        for(auto &entry:mp)
            if(entry.second >= mn)
                ans.push_back(entry.first);
        return ans;
    }
};
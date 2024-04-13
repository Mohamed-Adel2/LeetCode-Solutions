class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int freq[100001] ={};
        for(auto &x:nums)
            ++mp[x];
        for(auto &entry:mp)
            ++freq[entry.second];
        int mn;
        for(int i = 100000;i>=1;--i){
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
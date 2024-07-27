#include <bits/stdc++.h>
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> res(nums.size());
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i){
            mp[i] = nums[i];
            string num = to_string(nums[i]);
            for(int j = 0; j < num.size(); ++j)
                num[j] = mapping[num[j] - '0'] + '0';
            res[i] = {stoi(num), i};
        }
        sort(res.begin(), res.end());
        for(int i = 0; i < nums.size(); ++i)
            nums[i] = mp[res[i].second];
        return nums;
    }
};
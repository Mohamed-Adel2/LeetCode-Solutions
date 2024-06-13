class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefix = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            prefix += nums[i];
            prefix %= k;
            if(prefix < 0)
                prefix += k;
            ans += freq[prefix];
            ++freq[prefix];
        }
        return ans;
    }
};
class Solution {
public:
    int ans = 0;
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        solve(0, nums, k, freq);
        return ans - 1;
    }

    void solve(int idx, vector<int>& nums, int k, unordered_map<int, int>& freq){
        if(idx >= nums.size())
            return void(++ans);
        if(!freq[nums[idx] + k] && !freq[nums[idx] - k]){
            ++freq[nums[idx]];
            solve(idx + 1, nums, k, freq);
            --freq[nums[idx]];
        }
        solve(idx + 1, nums, k, freq);
    }
};
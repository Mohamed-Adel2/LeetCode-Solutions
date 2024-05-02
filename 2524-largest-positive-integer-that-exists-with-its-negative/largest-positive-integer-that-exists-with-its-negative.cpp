class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, bool> freq;
        int mx = -1001;
        for(auto &i : nums){
            if(freq.count(-i))
                mx = max(mx, abs(i));
            freq[i] = true;
        }
        return (mx == -1001 ? -1 : mx);
    }
};
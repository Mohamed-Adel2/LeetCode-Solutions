class Solution {
public:
    int specialArray(vector<int>& nums) {
        int freq[1002] = {};
        for(auto &num : nums)
            ++freq[num];
        for(int i = 1000; i >= 0; --i){
            freq[i] += freq[i + 1];
            if(i == freq[i])
                return i;
        } 
        return -1;
    }
};
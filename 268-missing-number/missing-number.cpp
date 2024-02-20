class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> freq(nums.size() + 1);
        for(int i = 0;i<nums.size();++i)
            ++freq[nums[i]];
        for(int i = 0;i<freq.size();++i)
            if(!freq[i])
                return i;
        return 0;
    }
};
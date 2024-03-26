class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0;i<nums.size();++i)
            if(nums[i] <= 0)
                nums[i] = 1e6;
        for(int i = 0;i<nums.size();++i)
            if(abs(nums[i]) <= nums.size())
                nums[abs(nums[i]) - 1] = abs(nums[abs(nums[i]) - 1]) * -1;
        
        for(int i = 0;i<nums.size();++i)
            if(nums[i] > 0)
                return i + 1;
        return nums.size() + 1;

    }
};
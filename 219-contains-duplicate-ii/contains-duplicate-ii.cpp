class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> idx;
        for(int i = 0;i<nums.size();++i){
            if(!idx.count(nums[i]))
                idx[nums[i]] = i;
            else{
                if(i - idx[nums[i]] <= k)
                    return true;
                else
                    idx[nums[i]] = i;
            }
        }
        return false;
    }
};
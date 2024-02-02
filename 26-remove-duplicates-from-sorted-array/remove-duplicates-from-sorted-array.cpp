class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        for(int i = 0;i<nums.size();i++){
            nums[curr] = nums[i];
            while(i < nums.size() && nums[i] == nums[curr])
                i++;
            i--;
            curr++;
        }
        return curr;
    }
};
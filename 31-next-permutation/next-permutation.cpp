class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 2; i >=0; --i){
            int idx = -1;
            for(int j = nums.size() - 1; j > i; --j){
                if(nums[j] > nums[i]){
                    if(idx == -1 || nums[j] < nums[idx])
                        idx = j;
                }
            }
            if(idx != -1){
                swap(nums[i], nums[idx]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};
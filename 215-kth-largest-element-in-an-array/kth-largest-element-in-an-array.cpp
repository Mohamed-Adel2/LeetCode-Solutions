class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> left, right;
        int pivot = nums[nums.size() / 2], pivotCnt = 0;
        for(int i = 0;i<nums.size(); ++i){
            if(nums[i] == pivot)
                ++pivotCnt;
            else if(nums[i] < pivot)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        if(right.size()>=k)
            return findKthLargest(right, k);
        else if(right.size() + pivotCnt >= k)
            return pivot;
        else
            return findKthLargest(left, k - pivotCnt - right.size());
    }
};
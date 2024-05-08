/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructSubTree(nums, 0, nums.size() - 1);
    }

    TreeNode* constructSubTree(vector<int>& nums, int startIdx, int endIdx){
        if(startIdx > endIdx)
            return NULL;
        int mid = (startIdx + endIdx) / 2;
        return new TreeNode(nums[mid], constructSubTree(nums, startIdx, mid - 1), constructSubTree(nums, mid + 1, endIdx));
    }
};
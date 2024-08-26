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
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<TreeNode*, map<int, int>> vis;
        solve(root, 0, 0, targetSum, ans, vis);
        return ans;
    }

    void solve(TreeNode* node, long long currSum, int cnt, int& targetSum, int& ans, unordered_map<TreeNode*, map<int, int>>& vis){
        if(!node || vis[node][cnt])
            return;
        currSum += node->val;
        vis[node][cnt]= true;
        if(currSum == targetSum)
            ++ans;
        solve(node->left, currSum, cnt + 1, targetSum, ans, vis);
        solve(node->left, 0, 0, targetSum, ans, vis);
        solve(node->right, currSum, cnt + 1, targetSum, ans, vis);
        solve(node->right, 0, 0, targetSum, ans, vis);
    }
};
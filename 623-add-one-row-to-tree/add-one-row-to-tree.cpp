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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
            return new TreeNode(val, root, NULL);
        solve(root,val, depth - 2);
        return root;
    }
    void solve(TreeNode* node, int val, int depth){
        if(!node)
            return;
        if(depth == 0){
            TreeNode* left = new TreeNode(val, node->left, NULL);
            TreeNode* right = new TreeNode(val, NULL, node->right);
            node->left = left, node->right = right;
            return;
        }
        solve(node->left, val, depth-1);
        solve(node->right, val, depth-1);
    }
};
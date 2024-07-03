class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
    void solve(TreeNode* node, int& sum){
        if(!node)
            return;
        solve(node->right, sum);
        node->val += sum;
        sum = node -> val;
        solve(node->left, sum);
    }

};
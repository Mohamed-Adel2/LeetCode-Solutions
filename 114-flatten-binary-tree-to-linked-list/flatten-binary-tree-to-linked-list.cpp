class Solution {
public:
    TreeNode *last;

    void flatten(TreeNode *root) {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        if (last)
            root->right = last;
        last = root;
    }
};
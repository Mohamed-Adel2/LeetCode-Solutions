class Solution {
public:
    TreeNode *last;

    void flatten(TreeNode *root) {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        if (last)
            root->right = last;
        root->left = NULL;
        last = root;
    }
};
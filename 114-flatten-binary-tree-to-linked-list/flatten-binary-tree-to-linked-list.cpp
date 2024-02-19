class Solution {
public:
    TreeNode *last;

    void flatten(TreeNode *root) {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        if (last != NULL)
            root->right = last;
        last = root;
    }
};
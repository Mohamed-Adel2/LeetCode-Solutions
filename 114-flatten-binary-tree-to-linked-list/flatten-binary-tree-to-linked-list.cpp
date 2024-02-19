class Solution {
public:
    TreeNode *last;

    void flatten(TreeNode *root) {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        if (last != NULL)
            root->right = last;
        root->left = NULL;
        last = root;
    }
};
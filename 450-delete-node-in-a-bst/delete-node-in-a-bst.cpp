class Solution {
public:
    int getMax(TreeNode* root) {
        if (!root)
            return -1;
        while (root->right)
            root = root->right;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* &root, int &key) {
        if (!root)
            return NULL;
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }
            if (root->left && !root->right) {
                TreeNode* leftChild = root->left;
                root->left = NULL;
                delete root;
                return leftChild;
            }
            if (root->right && !root->left) {
                TreeNode* rightChild = root->right;
                root->right = NULL;
                delete root;
                return rightChild;
            }
            if (root->right && root->left) {
                int nextMax = getMax(root->left);
                root->val = nextMax;
                root->left = deleteNode(root->left, nextMax);
                return root;
            }
        } else {
            if (key < root->val)
                root->left = deleteNode(root->left, key);
            else
                root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
class Solution {
public:
    TreeNode *balanceBST(TreeNode *root) {
        vector<int> val;
        traverse(root, val);
        if (val.size() < 3)
            return root;
        return constructSubTree(val, 0, val.size() - 1);
    }

    TreeNode *constructSubTree(vector<int> &val, int startIdx, int endIdx) {
        if (startIdx > endIdx)
            return NULL;
        int mid = (startIdx + endIdx) / 2;
        TreeNode *newRoot = new TreeNode(val[mid]);
        newRoot->left = constructSubTree(val, startIdx, mid - 1);
        newRoot->right = constructSubTree(val, mid + 1, endIdx);
        return newRoot;
    }

    void traverse(TreeNode *node, vector<int> &val) {
        if (!node)
            return;
        traverse(node->left, val);
        val.push_back(node->val);
        traverse(node->right, val);
    }
};
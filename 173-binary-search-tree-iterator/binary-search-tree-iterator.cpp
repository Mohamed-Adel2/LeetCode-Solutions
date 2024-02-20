class BSTIterator {
public:
    queue<int> inOrder;
    int minVal = INT32_MAX;

    BSTIterator(TreeNode *root) {
        inOrderTraversal(root);
        while (inOrder.front() != minVal)
            inOrder.pop();
    }

    void inOrderTraversal(TreeNode *node) {
        if (!node)
            return;
        inOrderTraversal(node->left);
        inOrder.push(node->val);
        minVal = min(minVal, node->val);
        inOrderTraversal(node->right);
    }

    int next() {
        int val = inOrder.front();
        inOrder.pop();
        return val;
    }

    bool hasNext() {
        return (!inOrder.empty());
    }
};
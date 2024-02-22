class Solution {
public:
    multiset<int> ms;

    int kthSmallest(TreeNode *root, int k) {
        dfs(root, k);
        return *ms.rbegin();
    }

    void dfs(TreeNode *node, int k) {
        if (!node)
            return;
        ms.insert(node->val);
        if (ms.size() > k)
            ms.erase(--ms.end());
        dfs(node->left, k);
        dfs(node->right, k);
    }
};
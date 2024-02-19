class Solution {
public:
    unordered_map<int, int> idx;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            idx[inorder[i]] = i;
        int sz = preorder.size();
        return solve(preorder, inorder, 0, sz - 1, 0, sz - 1);
    }

    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd)
            return NULL;
        TreeNode *node = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return node;
        node->left = solve(preorder, inorder, preStart + 1, preStart + idx[preorder[preStart]] - inStart, inStart, idx[preorder[preStart]] - 1);
        node->right = solve(preorder, inorder, preStart + 1 + idx[preorder[preStart]] - inStart, preEnd, idx[preorder[preStart]] + 1, inEnd);
        return node;
    }
};
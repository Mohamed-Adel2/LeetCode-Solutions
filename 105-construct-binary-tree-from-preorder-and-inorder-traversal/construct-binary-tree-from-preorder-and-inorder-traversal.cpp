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
        int val = preorder[preStart];
        TreeNode *node = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
            return node;
        int sz = idx[val] - inStart;
        node->left = solve(preorder, inorder, preStart + 1, preStart + sz, inStart, idx[val] - 1);
        node->right = solve(preorder, inorder, preStart + 1 + sz, preEnd, idx[val] + 1, inEnd);
        return node;
    }
};
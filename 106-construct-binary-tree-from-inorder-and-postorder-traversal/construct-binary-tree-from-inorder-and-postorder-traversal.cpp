class Solution {
public:
    unordered_map<int, int> idx;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for (int i = 0; i < postorder.size(); ++i)
            idx[inorder[i]] = i;
        int sz = postorder.size();
        return solve(inorder, postorder, 0, sz - 1, 0,sz - 1);
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (postStart > postEnd)
            return NULL;
        int val = postorder[postEnd];
        TreeNode *node = new TreeNode(postorder[postEnd]);
        if (postStart == postEnd)
            return node;
        int sz = idx[val] - inStart;
        node->left = solve(inorder, postorder, inStart, idx[val] - 1, postStart, postStart + sz - 1);
        node->right = solve(inorder, postorder, idx[val] + 1, inEnd, postStart + sz, postEnd - 1);
        return node;
    }
};
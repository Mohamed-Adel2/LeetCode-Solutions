class Solution {

    public TreeNode invertTree(TreeNode root) {
        solve(root);
        return root;
    }

    void solve(TreeNode node) {
        if (node == null)
            return;
        solve(node.left);
        solve(node.right);
        TreeNode tmp = node.left;
        node.left = node.right;
        node.right = tmp;
    }
}
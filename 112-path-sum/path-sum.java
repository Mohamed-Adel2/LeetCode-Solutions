class Solution {
    boolean valid = false;

    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null)
            return false;
        solve(root, targetSum);
        return valid;
    }

    void solve(TreeNode node, int sum) {
        if (node.left == null && node.right == null) {
            valid |= (sum - node.val == 0);
            return;
        }
        if (node.left != null)
            solve(node.left, sum - node.val);
        if (node.right != null)
            solve(node.right, sum - node.val);
    }
}
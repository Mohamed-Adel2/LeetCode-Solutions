class Solution {
    boolean valid = true;

    public boolean isSymmetric(TreeNode root) {
        if (root != null)
            solve(root.left, root.right);
        return valid;
    }

    void solve(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null)
            return;
        if (node1 == null || node2 == null || node1.val != node2.val) {
            valid = false;
            return;
        }
        solve(node1.right, node2.left);
        solve(node1.left, node2.right);
    }
}
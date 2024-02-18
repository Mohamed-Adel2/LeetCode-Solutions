class Solution {
    boolean valid = true;

    public boolean isSameTree(TreeNode p, TreeNode q) {
        solve(p, q);
        return valid;
    }

    void solve(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null)
            return;
        else if (node1 == null || node2 == null || (node1.val != node2.val)) {
            valid = false;
            return;
        }
        solve(node1.left, node2.left);
        solve(node1.right, node2.right);
    }
}
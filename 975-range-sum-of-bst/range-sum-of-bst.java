class Solution {
    int count = 0;

    public int rangeSumBST(TreeNode root, int low, int high) {
        dfs(root, low, high);
        return count;
    }

    public void dfs(TreeNode node, int low, int high) {
        if (node == null)
            return;
        count += (node.val >= low && node.val <= high ? node.val : 0);
        dfs(node.right, low, high);
        dfs(node.left, low, high);
    }
}
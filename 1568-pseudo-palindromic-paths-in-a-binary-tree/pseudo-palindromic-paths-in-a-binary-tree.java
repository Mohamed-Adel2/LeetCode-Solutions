/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int ans = 0;

    public int pseudoPalindromicPaths(TreeNode root) {
        dfs(root, 0);
        return ans;
    }

    public void dfs(TreeNode node, int val) {
        val ^= (1 << node.val);
        if (node.left == null && node.right == null) {
            if ((val & (val - 1)) == 0)
                ++ans;
            val ^= (1 << node.val);
            return;
        }
        if (node.left != null)
            dfs(node.left, val);
        if (node.right != null)
            dfs(node.right, val);
        val ^= (1 << node.val);
    }
}
class Solution {
    int moves;
    private int dfs(TreeNode root){
        if(root==null) return 0;
        int left = dfs(root.left);
        int right = dfs(root.right);
        moves += Math.abs(left) + Math.abs(right);
        return (root.val - 1) + right + left;
    }
    public int distributeCoins(TreeNode root) {
        dfs(root);
        return moves;
    }
}
class Solution {
    int mxDepth = 0;

    public int maxDepth(TreeNode root) {
        dfs(root, 0);
        return mxDepth;
    }

    public void dfs(TreeNode node, int depth) {
        if(node == null){
            mxDepth = Math.max(mxDepth, depth);
            return;
        }
        dfs(node.right, depth + 1);
        dfs(node.left, depth + 1);
    }
}
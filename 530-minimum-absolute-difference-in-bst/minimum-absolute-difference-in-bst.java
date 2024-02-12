class Solution {
    ArrayList<Integer> nodes = new ArrayList<>();

    public int getMinimumDifference(TreeNode root) {
        dfs(root);
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < nodes.size(); ++i)
            ans = Math.min(ans, nodes.get(i) - nodes.get(i - 1));
        return ans;
    }

    public void dfs(TreeNode node) {
        if (node == null)
            return;
        dfs(node.left);
        nodes.add(node.val);
        dfs(node.right);
    }
}
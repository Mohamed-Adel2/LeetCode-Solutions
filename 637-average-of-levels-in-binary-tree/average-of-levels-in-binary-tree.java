class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> ans = new ArrayList<>();
        List<Integer> levels = new ArrayList<>();
        solve(root, 1, ans, levels);
        for (int i = 0; i < ans.size(); ++i)
            ans.set(i, ans.get(i) / levels.get(i));
        return ans;
    }

    void solve(TreeNode node, int depth, List<Double> vals, List<Integer> levels) {
        if (node == null)
            return;
        if (vals.size() < depth) {
            vals.add((double) node.val);
            levels.add(1);
        } else {
            vals.set(depth - 1, vals.get(depth - 1) + node.val);
            levels.set(depth - 1, levels.get(depth - 1) + 1);
        }
        solve(node.left, depth + 1, vals, levels);
        solve(node.right, depth + 1, vals, levels);
    }

}
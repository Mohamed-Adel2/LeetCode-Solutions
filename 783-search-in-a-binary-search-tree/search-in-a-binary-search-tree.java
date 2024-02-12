class Solution {
    TreeNode ans = null;

    public TreeNode searchBST(TreeNode root, int val) {
        dfs(root, val);
        return ans;
    }

    public void dfs(TreeNode node, int val){
        if(node == null)
            return;
        if(node.val == val){
            ans = node;
            return;
        }
        if(node.val < val)
            dfs(node.right, val);
        else
            dfs(node.left, val);
    }
}

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return (solve(root, target) ? NULL : root);
    }

    bool solve(TreeNode* node, int target){
        bool removable = (node -> val == target), ret;
        if(node -> left){
            ret = solve(node -> left, target);
            if(ret)
                node -> left = NULL;
            removable &= ret;
        }
        if(node -> right){
            ret = solve(node -> right, target);
            if(ret)
                node -> right = NULL;
            removable &= ret;
        }
        return removable;
    }
};
class Solution {
public:
    bool isEvenOddTree(TreeNode *root) {
        queue<pair<TreeNode *, int>> q;
        pair<TreeNode*, int> top;
        q.push({root, 0});
        while (!q.empty()) {
            top = q.front();
            q.pop();
            if (((top.second & 1) && (top.first->val & 1)) ||
                ((top.second & 1) && !q.empty() && q.front().second == top.second && q.front().first->val <= top.first->val))
                return false;
            if ((!(top.second & 1) && !(top.first->val & 1)) ||
                (!(top.second & 1) && !q.empty() && q.front().second == top.second && q.front().first->val >= top.first->val))
                return false;
            if (top.first->right)
                q.push({top.first->right, top.second + 1});
            if (top.first->left)
                q.push({top.first->left, top.second + 1});
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            pair<TreeNode *, int> node = q.front();
            q.pop();
            if (node.second > ans.size())
                ans.emplace_back(vector<int>());
            ans.back().emplace_back(node.first->val);
            if (node.first->left)
                q.push({node.first->left, node.second + 1});
            if (node.first->right)
                q.push({node.first->right, node.second + 1});
        }
        return ans;
    }
};
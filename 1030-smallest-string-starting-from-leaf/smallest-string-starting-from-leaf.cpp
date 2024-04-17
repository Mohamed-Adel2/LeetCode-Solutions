class Solution {
public:
    vector<string> leafs;
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        solve(root, s);
        sort(leafs.begin(), leafs.end());
        return leafs[0];
    }

    void solve(TreeNode* node, string& str){
        str.push_back((node->val + 'a'));
        if(!node->left && !node->right){
            string rev = str;
            reverse(rev.begin(), rev.end());
            leafs.push_back(rev);
            str.pop_back();
            return;
        }
        if(node->left)
            solve(node->left, str);
        if(node->right)
            solve(node->right, str);
        str.pop_back();
    }
};
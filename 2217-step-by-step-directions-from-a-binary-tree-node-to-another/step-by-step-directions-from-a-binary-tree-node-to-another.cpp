class Solution {
public:
    string start, end;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        int idx = 0;
        string path;
        dfs(root, startValue, destValue, path);
        while(idx < start.size() && idx < end.size() && start[idx] == end[idx])
            ++idx;
        string ans;
        for(int i = idx; i < start.size(); ++i)
            ans.push_back('U');
        for(int i = idx; i < end.size(); ++i)
            ans.push_back(end[i]);
        return ans;
    }
    void dfs(TreeNode* node, int startValue, int destValue, string& path){
        if(!node || (!start.empty() && !end.empty()))
            return;
        if(node -> val == startValue)
            start = path;
        if(node -> val == destValue)
            end = path;
        path.push_back('L');
        dfs(node -> left, startValue, destValue, path);
        path.pop_back();
        path.push_back('R');
        dfs(node -> right, startValue, destValue, path);
        path.pop_back();
    }
};
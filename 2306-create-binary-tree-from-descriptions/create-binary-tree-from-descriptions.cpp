class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, bool> isChild;
        unordered_map<int, TreeNode*> node;
        for(int i = 0; i < descriptions.size(); ++i){
            int parent = descriptions[i][0], child = descriptions[i][1], isLeft = descriptions[i][2]; 
            TreeNode* parentNode, *childNode;
            if(node.contains(parent))
                parentNode = node[parent];
            else {
                parentNode = new TreeNode(parent);
                node[parent] = parentNode;
            }
            if(node.contains(child))
                childNode = node[child];
            else {
                childNode = new TreeNode(child);
                node[child] = childNode;
            } 
            if(isLeft)
                parentNode -> left = childNode;
            else
                parentNode -> right = childNode;
            isChild[child] = true;
            isChild[parent] |= false;
        }
        for(auto &i : isChild)
            if(i.second == false)
                return node[i.first];
        return NULL;
    }
};
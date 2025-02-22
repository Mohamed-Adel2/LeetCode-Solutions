class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int last = -1;
        bool left = true;
        vector<TreeNode*> nodes;
        nodes.push_back(new TreeNode(-1));
        for (int i = 0; i < traversal.size(); ++i) {
            int curr = 0;
            while (traversal[i] == '-')
                ++curr, ++i;
            if (curr <= last) {
                while (curr <= last)
                    nodes.pop_back(), --last;
                left = false;
            } else
                left = true;
            last = curr;
            string num;
            while (i < traversal.size() && traversal[i] != '-')
                num += traversal[i++];
            --i;
            TreeNode* newNode = new TreeNode(stoi(num));
            if (left)
                nodes.back()->left = newNode;
            else
                nodes.back()->right = newNode;
            nodes.push_back(newNode);
        }
        return nodes[1];
    }
};
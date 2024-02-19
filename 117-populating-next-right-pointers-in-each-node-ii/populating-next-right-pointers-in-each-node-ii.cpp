class Solution {
public:
    Node *connect(Node *root) {
        if(root == NULL)
            return NULL;
        deque<pair<Node *, int>> q;
        q.emplace_back(root, 1);
        while (!q.empty()) {
            pair<Node *, int> top = q.front();
            q.pop_front();
            if (!q.empty() && q.front().second == top.second)
                top.first->next = q.front().first;
            if (top.first->left != NULL)
                q.emplace_back(top.first->left, top.second + 1);
            if (top.first->right != NULL)
                q.emplace_back(top.first->right, top.second + 1);
        }
        return root;
    }
};
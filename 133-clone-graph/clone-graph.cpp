class Solution {
public:
    unordered_map<int, Node *> mp;
    unordered_map<int, bool> vis;

    Node *cloneGraph(Node *node) {
        if (!node)
            return NULL;
        Node *newNode = new Node(node->val);
        mp[node->val] = newNode;
        vis[node->val] = true;
        for (auto &i: node->neighbors) {
            if (!vis[i->val])
                newNode->neighbors.emplace_back(cloneGraph(i));
            else
                newNode->neighbors.emplace_back(mp[i->val]);
        }
        return newNode;
    }
};
class Solution {
public:
    map<int, Node *> mp;
    map<int, bool> vis;

    Node *cloneGraph(Node *node) {
        if (!node)
            return NULL;
        Node *newNode = new Node(node->val);
        mp[node->val] = newNode;
        vis[node->val] = true;
        for (auto &i: node->neighbors) {
            if (!vis[i->val])
                newNode->neighbors.push_back(cloneGraph(i));
            else
                newNode->neighbors.push_back(mp[i->val]);
        }
        return newNode;
    }
};
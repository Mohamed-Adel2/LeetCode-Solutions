class Solution {
public:
    unordered_map<int, Node *> mp;

    Node *cloneGraph(Node *node) {
        if (!node)
            return NULL;
        Node *newNode = new Node(node->val);
        mp[node->val] = newNode;
        for (auto &i: node->neighbors) {
            if (!mp.count(i->val))
                newNode->neighbors.emplace_back(cloneGraph(i));
            else
                newNode->neighbors.emplace_back(mp[i->val]);
        }
        return newNode;
    }
};
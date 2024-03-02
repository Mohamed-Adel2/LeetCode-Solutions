class Solution {
public:
    Node *copyRandomList(Node *head) {
        map<Node *, Node *> mp;
        Node *node = head;
        while (node) {
            mp[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while (node) {
            mp[node]->random = mp[node->random];
            mp[node]->next = mp[node->next];
            node = node->next;
        }
        return mp[head];
    }
};
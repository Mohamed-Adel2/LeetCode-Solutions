class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return NULL;
        map<Node *, Node *> mp;
        Node *node = head;
        while (node) {
            Node *tmp = new Node(node->val);
            mp[node] = tmp;
            node = node->next;
        }
        node = head;
        while (node) {
            if (node->random)
                mp[node]->random = mp[node->random];
            if(node->next)
                mp[node]->next = mp[node->next];
            node = node->next;
        }
        return mp[head];
    }
};
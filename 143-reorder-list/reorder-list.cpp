class Solution {
public:
    void reorderList(ListNode *head) {
        vector<int> v;
        ListNode *node = head;
        while (node)
            v.push_back(node->val), node = node->next;
        int l = 0, r = v.size() - 1;
        bool left = true;
        node = head;
        while (node) {
            if (left)
                node->val = v[l++];
            else
                node->val = v[r--];
            node = node->next;
            left ^= 1;
        }
    }
};
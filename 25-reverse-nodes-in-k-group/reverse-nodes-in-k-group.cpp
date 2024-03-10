class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        vector<int> vals;
        ListNode *node = head;
        while (node)
            vals.push_back(node->val), node = node->next;
        int cnt = 0, g = 1;
        node = head;
        while (node) {
            if (g * k > vals.size())
                break;
            node->val = vals[g * k - cnt++ - 1];
            node = node->next;
            if (cnt == k)
                ++g, cnt %= k;
        }
        return head;
    }
};
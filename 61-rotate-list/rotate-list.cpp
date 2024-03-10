class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head)
            return head;
        int sz = 0;
        ListNode *node = head, *tail;
        while (node)
            tail = node, ++sz, node = node->next;
        k %= sz;
        if (k == 0)
            return head;
        node = head;
        int cnt = 0;
        tail->next = head;
        while (node) {
            if (cnt == sz - k - 1) {
                tail = node->next;
                node->next = NULL;
                break;
            }
            ++cnt;
            node = node->next;
        }
        return tail;
    }
};
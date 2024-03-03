class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        int cnt = 0;
        ListNode *befLeft = NULL, *aftRight = NULL, *rightNode, *leftNode, *node = new ListNode(-1);
        node->next = head;
        while (node) {
            ++cnt;
            if (cnt == left)
                befLeft = node, leftNode = node->next;
            if (cnt == right)
                rightNode = node->next, aftRight = node->next->next;
            node = node->next;
        }
        if (befLeft && befLeft->val != -1)
            befLeft->next = rightNode;
        ListNode *first = leftNode, *second = leftNode->next, *tmp;
        while (first != rightNode && first) {
            tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }

        leftNode->next = aftRight;
        return (left != 1 ? head : rightNode);
    }
};
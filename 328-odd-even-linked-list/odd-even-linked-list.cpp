class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *odd = head, *even = head->next;
        ListNode *node = even->next, *firstEven = head->next;
        while (node) {
            odd->next = node;
            even->next = node->next;
            even = even->next;
            odd = odd->next;
            if (even && even->next)
                node = even->next;
            else
                break;
        }
        odd->next = firstEven;
        return head;
    }
};
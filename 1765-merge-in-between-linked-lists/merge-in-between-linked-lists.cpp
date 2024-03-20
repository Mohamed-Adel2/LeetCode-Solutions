class Solution {
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *node = list1, *secondTail = list2;
        while (secondTail->next)
            secondTail = secondTail->next;
        int curr = 0;
        while (node) {
            if (curr == a - 1) {
                ListNode *tmp = node->next;
                node->next = list2, node = tmp;
            } else if (curr == b) {
                secondTail->next = node->next, node->next = NULL;
                break;
            } else
                node = node->next;
            ++curr;
        }
        return list1;
    }
};
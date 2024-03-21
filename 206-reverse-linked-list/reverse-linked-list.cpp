
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head)
            return head;
        ListNode *curr = head, *next = head->next, *tmp;
        head->next = NULL;
        while (next)
            tmp = next->next, next->next = curr, curr = next, next = tmp;
        return curr;
    }
};

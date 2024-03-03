class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *newHead = head;
        int val = -101;
        while (newHead && (newHead->val == val || (newHead->next && newHead->next->val == newHead->val)))
            val = newHead->val, newHead = newHead->next;
        if (!newHead)
            return NULL;
        ListNode *prv = newHead, *curr = newHead->next;
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                val = curr->val;
                while (curr && curr->val == val)
                    curr = curr->next;
            } else
                prv->next = curr, prv = curr, curr = curr->next;
        }
        prv->next = curr;
        return newHead;
    }
};
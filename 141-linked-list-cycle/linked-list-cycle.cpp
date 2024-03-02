class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        while (head->next) {
            if (head->next->val == -1e6)
                return true;
            head->val = -1e6, head = head->next;
        }
        return false;
    }
};
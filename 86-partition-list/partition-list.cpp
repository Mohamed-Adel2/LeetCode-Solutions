class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fPtr = dummy, *prv = NULL, *curr = head;
        while(curr){
            if(curr->val < x && prv){
                prv->next = curr->next;
                curr->next = fPtr->next;
                fPtr->next = curr;
                fPtr = curr;
            }
            else if(curr->val < x)
                fPtr = curr;
            prv = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};
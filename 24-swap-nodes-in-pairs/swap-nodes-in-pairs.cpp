class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        ListNode* tmp = new ListNode();
        tmp->next = head;
        ListNode* prv = tmp, *first = head, *second = head->next;
        while(first && second){
            prv->next = second;
            first->next = second->next;
            second->next = first;
            prv = first;
            first = first->next;
            if(first)
                second = first->next;
        }
        return tmp->next;
    }
};
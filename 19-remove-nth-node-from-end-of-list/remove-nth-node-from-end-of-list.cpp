class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        int cnt = 0;
        while(node)
            ++cnt, node = node->next;
        if(cnt - n + 1 == 1)
            return head->next;
        node = head;
        while(node){
            if(cnt - ++n + 1 == 1){
                node->next = node->next->next;
                break;
            }
            node = node -> next;
        }
        return head;
    }
};
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = NULL, *node = head, *newTail = NULL;
        int sum = 0;
        while(node){
            if(node -> val == 0 && sum > 0){
                ListNode* tmp = new ListNode(sum);
                sum = 0;
                if(newTail == NULL)
                    newHead = newTail = tmp;
                else {
                    newTail->next = tmp;
                    newTail = tmp;
                }
            }
            else
                sum += node->val;
            node = node -> next;
        }
        return newHead;
    }
};
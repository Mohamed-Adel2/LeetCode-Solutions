class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* head, *node;
        if(list1->val <= list2->val)
            head = list1, list1 = list1->next;
        else
            head = list2, list2 = list2->next;
        node = head;
        while(list1 && list2){
            if(list1->val <= list2->val)
                node->next = list1, list1 = list1->next, node = node->next;
            else
                node->next = list2, list2 = list2->next, node = node->next;
        }
        if(list2)
            node->next = list2;
        else
            node->next = list1;
        return head;

    }
};
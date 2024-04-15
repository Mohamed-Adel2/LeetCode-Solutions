/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
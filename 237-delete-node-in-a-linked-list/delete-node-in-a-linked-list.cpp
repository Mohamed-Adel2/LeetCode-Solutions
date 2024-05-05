/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nxt = node -> next;
        while(nxt){
            node -> val = nxt ->val;
            if(nxt -> next == NULL)
                node -> next = NULL;
            nxt = nxt -> next, node = node -> next;
        }
    }
};
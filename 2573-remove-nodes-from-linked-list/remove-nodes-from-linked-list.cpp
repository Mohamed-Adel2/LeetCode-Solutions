class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        multiset<int> ms;
        ListNode* start = head;
        while(start){
            ms.insert(start->val);
            start = start->next;
        }
        start = new ListNode(0);
        start -> next = head;
        ListNode* prv = start, *node = head, *nxt;
        while(node){
            nxt = node -> next;
            if(*ms.rbegin() > node -> val)
                prv -> next = nxt;
            else
                prv = node;
            ms.erase(ms.find(node -> val));
            node = nxt;
        }
        return start->next;
    }
};
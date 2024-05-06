class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> vals;
        ListNode* start = head;
        while(start)
            vals.push_back(start->val), start = start->next;
        int sz = vals.size(), cnt = 0;
        reverse(vals.begin(), vals.end());
        for(int i = 1; i<sz;++i)
            vals[i] = max(vals[i], vals[i - 1]);
        start = new ListNode(0);
        ListNode* prv = start, *node = head, *nxt;
        start -> next = head;
        while(node){
            nxt = node -> next;
            if(vals[sz - 1 - cnt++] > node -> val)
                prv -> next = nxt;
            else
                prv = node;
            node = nxt;
        }
        return start->next;
    }
};
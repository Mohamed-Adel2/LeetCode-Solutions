class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<pair<int, ListNode*>> st;
        for(int i = 0; i < lists.size(); ++i)
            if(lists[i])
                st.insert({lists[i]->val, lists[i]});
        ListNode* head = new ListNode(-1);
        ListNode* last = head;
        while(!st.empty()){
            pair<int, ListNode*> mn = *st.begin();
            st.erase(st.begin());
            last->next = mn.second;
            last = mn.second;
            if(mn.second->next)
                st.insert({mn.second->next->val, mn.second->next});
        }
        return head->next;
    }
};
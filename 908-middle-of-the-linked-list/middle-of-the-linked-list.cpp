class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* node = head;
        mp[1] = head;
        int cnt = 1;
        while(node->next){
            node = node->next;
            mp[++cnt] = node;
        }
        return mp[cnt / 2 + 1];
    }
};
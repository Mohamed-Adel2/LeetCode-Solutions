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
    ListNode* sortList(ListNode* head) {
        if(!head)
            return head;
        vector<pair<int, ListNode*>> v;
        ListNode* node = head;
        while(node){
            v.push_back({node -> val, node});
            node = node -> next;
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size() - 1; ++i)
            v[i].second -> next = v[i + 1].second;
        v.back().second -> next = NULL;
        return v[0].second;
    }
};
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        string sum;
        ListNode* node = head;
        while(node)
            sum.push_back(node -> val + '0'), node = node -> next;
        int carry = 0;
        for(int i = sum.size(); i >= 0; --i){
            int tmp = (sum[i] - '0') * 2 + carry;
            carry = tmp >= 10, sum[i] = (tmp % 10) + '0';
        }
        if(carry)
            sum = '1' + sum;
        node = head;
        int idx = 0;
        while(node){
            node -> val = sum[idx++] - '0';
            if(node -> next == NULL && idx < sum.size()){
                ListNode* tmp = new ListNode(sum[idx] - '0');
                node -> next = tmp;
                break;
            }
            node = node -> next;
        }
        return head;
    }
};
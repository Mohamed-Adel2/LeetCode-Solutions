class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans{-1, -1};
        int prv = head -> val, curr = head -> next -> val, cnt = 1;
        ListNode* node = head -> next;
        vector<int> idx;
        while(node -> next){
            if(isCritical(prv, curr, node -> next -> val))
                idx.push_back(cnt);
            ++cnt, node = node -> next, prv = curr, curr = node -> val;
        }
        if(idx.size() > 1){
            ans[1] = idx.back() - idx[0];
            ans[0] = 1e6;
            for(int i = 0; i < idx.size() - 1; ++i)
                ans[0] = min(ans[0], idx[i + 1] - idx[i]);
        }
        return ans;
    }

    bool isCritical(int prv, int curr, int next){
        return (curr < prv && curr < next) || (curr > prv && curr > next);
    }
};
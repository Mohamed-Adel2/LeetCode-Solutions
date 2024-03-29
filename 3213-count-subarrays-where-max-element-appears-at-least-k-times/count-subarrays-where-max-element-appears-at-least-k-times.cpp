class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0, sz = nums.size();
        long long ans = 0;
        for(int i = 0;i<sz;++i)
            mx = max(mx, nums[i]);
        int left = 0, right = 0, cnt = 0;
        deque<int> el;
        while(right < sz){
            if(nums[right] == mx)
                el.push_back(right), ++cnt;
            if(cnt == k){
                long long before = el.front() - left, after = sz - right - 1;
                ans += before + after + before * after + 1;
                while(nums[left++] != mx);
                --cnt;
                el.pop_front();
            }
            ++right;
        }
        return ans;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int first = -1, second = -1;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            int cnt = 0, j = i;
            while(j < nums.size() && nums[j] == 1)
                ++cnt, ++j;
            i = j;
            if(first == -1)
                first = cnt;
            else if(second == -1)
                second = cnt, ans = max(ans, first + second);
            else
                first = second, second = cnt, ans = max(ans, first + second);
        }
        if(second == -1)
            ans = max(first - 1, 0);
        return ans;
    }
};
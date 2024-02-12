class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0, end = (int)height.size() - 1;
        int ans = 0;
        while(st < end){
            ans = max(ans, (end - st) * min(height[st], height[end]));
            if(height[st] <= height[end])
                ++st;
            else
                --end;
        }
        return ans;
    }
};
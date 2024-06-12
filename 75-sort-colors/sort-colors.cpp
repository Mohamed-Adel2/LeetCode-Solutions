class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3] = {};
        for(auto &i : nums)
            color[i]++;
            int ptr = 0;
        for(int i = 0; i < 3; ++i)
            while(color[i]--)
                nums[ptr++] = i;
    }
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT32_MAX, s = INT32_MAX;
        for(auto &i : nums){
            if(i <= f)
                f = i;
            else if(i <= s)
                s = i;
            else
                return true;
        }
        return false;
    }
};
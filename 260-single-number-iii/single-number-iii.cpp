class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorSum = 0;
        int first = 0, second = 0;
        for(auto &num : nums)
            xorSum ^= num;
        for(int i = 0; i < 32; ++i){
            if(xorSum & (1 << i)){
                for(auto &num : nums){
                    if(num & (1 << i))
                        first ^= num;
                    else
                        second ^= num;
                }
                break;
            }
        }
        vector<int> ans{first, second};
        return ans;
    }
};
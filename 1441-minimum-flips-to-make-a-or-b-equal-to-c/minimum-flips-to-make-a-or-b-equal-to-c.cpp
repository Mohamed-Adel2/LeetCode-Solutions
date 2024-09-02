class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            if((1 << i) & c){
                if(!((1 << i) & a) && !((1 << i) & b))
                    ++ans;
            }
            else
                if(((1 << i) & a) && ((1 << i) & b))
                    ans += 2;
                else if(((1 << i) & a) || ((1 << i) & b))
                    ++ans;
        }
        return ans;
    }
};
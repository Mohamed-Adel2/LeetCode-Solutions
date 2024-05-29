class Solution {
public:
    int numSteps(string s) {
        int carry = 0, ans = 0;
        for(int i = s.size() - 1; i > 0; --i){
            ++ans;
            if(carry && s[i] == '0')
                ++ans;
            else if(!carry && s[i] == '1')
                ++ans, carry = 1;
        }
        if(carry)
            ++ans;
        return ans;  
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        bool carry = true;
        for(int i = 0;i<digits.size();++i){
            digits[i] += carry;
            carry = false;
            if(digits[i] == 10)
                digits[i] = 0, carry = true;
            else
                break;
        }
        if(carry)
            digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
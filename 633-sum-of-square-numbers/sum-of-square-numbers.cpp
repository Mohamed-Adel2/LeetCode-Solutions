class Solution {
public:
    bool judgeSquareSum(int c) {
        if(!c)
            return true;
        for(long long i = 1; i * i <= c; ++i){
            long long num = sqrt(c - i * i);
            if(num * num == - (i * i) + c)
                return true;
        }
        return false;
    }
};
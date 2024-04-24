class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n < 3)
            return 1;
        vector<int> v{0, 1, 1};
        n-=2;
        int ans;
        while(n--){
            ans = v[0] + v[1] + v[2];
            v[0] = v[1], v[1] = v[2], v[2] = ans; 
        }
        return ans;
    }
};
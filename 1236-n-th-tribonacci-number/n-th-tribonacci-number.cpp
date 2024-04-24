class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n < 3)
            return 1;
        vector<int> ans(n + 1);
        ans[0] = 0, ans[1] = ans[2] = 1, ans[3] = 2;
        int sum = 2;
        for(int i = 4;i<=n;++i){
            sum = sum - ans[i - 4] + ans [i - 1];
            ans[i] = sum;
        }
        return ans[n];
    }
};
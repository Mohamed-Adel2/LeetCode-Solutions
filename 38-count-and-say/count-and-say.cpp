class Solution {
public:
    string countAndSay(int n) {
        vector<string> ans(n + 1);
        ans[1] = "1";
        for(int i = 2; i <= n;++i){
            for(int j = 0; j < ans[i-1].size();++j){
                int cnt = 0;
                char c = ans[i-1][j];
                while(j < ans[i-1].size() && ans[i-1][j] == c)
                    ++j, ++cnt;
                --j;
                ans[i].push_back(cnt + '0');
                ans[i].push_back(c);
            }
        }
        return ans[n];
    }
};
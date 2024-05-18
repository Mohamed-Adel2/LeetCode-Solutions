class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); ++i){
            int idx = 0;
            bool ok = true;
            for(char &c : queries[i]){
                if(c < 'a'){
                    if(idx == pattern.size() || c != pattern[idx++]){
                        ok = false;
                        break;
                    }
                }
                else if(idx < pattern.size() && c == pattern[idx])
                    ++idx;
            }
            ans[i] = (idx == pattern.size()) && ok;
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(ans, s, 0);
        return ans;
    }

    void solve(vector<string>& ans, string& s, int idx){
        if(idx == s.size())
            return void(ans.push_back(s));
        solve(ans, s, idx + 1);
        if(s[idx] >= 'a' && s[idx] <='z'){
            char c = s[idx];
            s[idx] -= 'a' - 'A';
            solve(ans, s, idx + 1);
            s[idx] = c;
        }
        else if(s[idx] >= 'A' && s[idx] <='Z'){
            char c = s[idx];
            s[idx] += 'a' - 'A';
            solve(ans, s, idx + 1);
            s[idx] = c;
        }
    }
};
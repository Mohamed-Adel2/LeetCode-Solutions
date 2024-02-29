class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string curr;
        solve(ret, curr, 2 * n, 0);
        return ret;
    }

    void solve(vector<string>& ret, string& curr, int idx, int open){
        if(idx == 0){
            if(!open)
                ret.push_back(curr);
            return;
        }
        if(open){
            curr.push_back(')');
            solve(ret, curr, idx - 1, open - 1);
            curr.pop_back();
        }
        curr.push_back('(');
        solve(ret, curr, idx - 1, open + 1);
        curr.pop_back();
    }
};
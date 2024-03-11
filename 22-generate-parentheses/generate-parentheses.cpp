class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string curr;
        solve(ret, curr, 2 * n, n, n);
        return ret;
    }

    void solve(vector<string>& ret, string& curr, int idx, int open, int close){
        if(idx == 0)
            return void(ret.push_back(curr));
        if(open < close){
            curr.push_back(')');
            solve(ret, curr, idx - 1, open, close - 1);
            curr.pop_back();
        }
        if(open > 0){
        curr.push_back('(');
        solve(ret, curr, idx - 1, open - 1, close);
        curr.pop_back();
        }
    }
};
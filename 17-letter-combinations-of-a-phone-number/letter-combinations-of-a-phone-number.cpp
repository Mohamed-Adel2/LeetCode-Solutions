class Solution {
public:
    vector<vector<char>> mapping;
    string curr;
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        char curr = 'a';
        mapping.resize(10);
        for(int i = 2;i<=9;i++)
            for(int j = 0;j<(i == 7 || i == 9 ? 4:3);j++)
                mapping[i].push_back(curr++);
        vector<string> ret;
        solve(ret, digits, 0);
        return ret;
    }
    void solve(vector<string>& ret,string& digits, int idx){
        if(idx == digits.size()){
            ret.push_back(curr);
            return;
        }
        for(int i=0;i<mapping[digits[idx]-'0'].size();i++){
            curr.push_back(mapping[digits[idx]-'0'][i]);
            solve(ret, digits, idx+1);
            curr.pop_back();
        }
    }
};
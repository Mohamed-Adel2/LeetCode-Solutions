class Solution {
public:
    vector<vector<string>> ans;    
    void solve(string& s, int i, vector<string>& subAns, string& sub){
        if(i >= s.size()){
            if(!sub.empty()){
                if(isPalindrome(sub)){
                    subAns.push_back(sub);
                    ans.push_back(subAns);
                    subAns.pop_back();
                }
                return;
            }
            ans.push_back(subAns);
            return;
        }

        if(!sub.empty() && isPalindrome(sub)){
            subAns.push_back(sub);
            string temp;
            temp += s[i];
            solve(s, i+1, subAns, temp);
            subAns.pop_back();
        }

        sub.push_back(s[i]);
        solve(s, i + 1, subAns, sub);
        sub.pop_back();
    }
    vector<vector<string>> partition(string s) {
        int sz = s.size();
        vector<string> subAns;
        string sub;
        solve(s, 0, subAns, sub);
        return ans;
    }

    bool isPalindrome(string s){
        for(int i = 0; i<s.size()/2; ++i)
            if(s[i] != s[s.size()-i-1])
                return false;
        return true;
    }
};
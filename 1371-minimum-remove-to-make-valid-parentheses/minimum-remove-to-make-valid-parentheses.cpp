class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        vector<bool> valid(s.size());
        stack<int> st;
        for(int i = 0;i<s.size();++i){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                if(!st.empty()){
                    valid[i] = valid[st.top()] = true;
                    st.pop();
                }
            }
            else
                valid[i] = true;
        }
        for(int i = 0;i<s.size();++i)
            if(valid[i])
                ans.push_back(s[i]);
        return ans;    
    }
};
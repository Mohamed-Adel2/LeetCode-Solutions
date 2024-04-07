class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stars, parenthesis;
        for(int i = 0;i<s.size();++i){
            if(s[i] == '*')
                stars.push(i);
            else if(s[i] == '(')
                parenthesis.push(i);
            else if(s[i] == ')' && !parenthesis.empty())
                parenthesis.pop();
            else if(s[i] == ')' && !stars.empty())
                stars.pop();
            else
                return false;
        }
        while(!stars.empty() && !parenthesis.empty() && parenthesis.top() < stars.top())
            stars.pop(), parenthesis.pop();
        return parenthesis.empty();
    }
};
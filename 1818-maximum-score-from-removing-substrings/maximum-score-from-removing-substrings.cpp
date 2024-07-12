class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string tmp;
        int ans = 0;
        if(x > y){
            for(int i = 0; i < s.size(); ++i){
                if(!tmp.empty() && tmp.back() == 'a' && s[i] == 'b')
                    ans += x, tmp.pop_back();
                else
                    tmp.push_back(s[i]);
            }
            s = "";
            for(int i = 0; i < tmp.size(); ++i){
                if(!s.empty() && s.back() == 'b' && tmp[i] == 'a')
                    ans += y, s.pop_back();
                else
                    s.push_back(tmp[i]);
            }
        }
        else {
            for(int i = 0; i < s.size(); ++i){
                if(!tmp.empty() && tmp.back() == 'b' && s[i] == 'a')
                    ans += y, tmp.pop_back();
                else
                    tmp.push_back(s[i]);
            }
            s = "";
            for(int i = 0; i < tmp.size(); ++i){
                if(!s.empty() && s.back() == 'a' && tmp[i] == 'b')
                    ans += x, s.pop_back();
                else
                    s.push_back(tmp[i]);
            }
        }
        return ans;
    }
};
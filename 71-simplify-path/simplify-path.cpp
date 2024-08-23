class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int sz = path.size();
        for(int i = 0; i < sz; ++i){
            while(i < sz && path[i] == '/')
                ++i;
            string ret = getNextPart(i, path);
            if(ret == ".." && !st.empty())
                st.pop_back();
            else if(ret == "." || ret.empty())
                continue;
            else if(ret != "..")
                st.push_back(ret);
        }
        if(st.empty())
            return "/";
        string ans;
        for(auto &s : st)
            ans += "/" + s;
        return ans; 
    }
    string getNextPart(int& idx, string& path){
        string ret;
        for(;idx < path.size(); ++idx){
            if(path[idx] == '/')
                break;
            ret += path[idx];
        }
        return ret;
    }
};
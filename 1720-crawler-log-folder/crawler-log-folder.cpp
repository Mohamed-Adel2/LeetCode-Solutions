class Solution {
public:
    int minOperations(vector<string>& logs) {
        string stay = "./", back = "../";
        int depth = 0;
        for(auto &log : logs){
            if(log == stay)
                continue;
            else if(log == back)
                depth = max(0, depth - 1);
            else
                ++depth;
        }
        return depth;
    }
};
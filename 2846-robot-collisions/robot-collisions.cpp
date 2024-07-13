class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, int>> v;
        for(int i = 0; i < positions.size(); ++i)
            v.push_back({positions[i], i});
        sort(v.begin(), v.end());
        stack<int> st;
        for(int i = 0; i < v.size(); ++i){
            int pos = v[i].second;
            while(!st.empty() && directions[pos] == 'L' && directions[st.top()] == 'R'){
                if(healths[pos] > healths[st.top()])
                    healths[st.top()] = 0, st.pop(), --healths[pos];
                else if(healths[pos] == healths[st.top()]){
                    healths[pos] = healths[st.top()] = 0, st.pop();
                    break;
                }
                else{
                    healths[pos] = 0, --healths[st.top()];
                    break;
                }
            }
            if(healths[pos] > 0)
                st.push(pos);
        }
        vector<int> ans;
        for(int i = 0; i < positions.size(); ++i)
            if(healths[i] > 0)
                ans.push_back(healths[i]);
        return ans;
    }
};
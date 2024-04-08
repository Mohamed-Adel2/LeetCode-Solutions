class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stZero = 0, stOne = 0;
        for(int i =0;i<students.size();++i)
            if(students[i])
                ++stOne;
            else
                ++stZero;
        int ans = 0;
        for(int i = 0;i<sandwiches.size();++i){
            if(sandwiches[i] == 1){
                if(stOne)
                    ++ans, --stOne;
                else break;
            }
            else{
                if(stZero)
                    ++ans, --stZero;
                else
                    break;
            }
        }
        return sandwiches.size() - ans;
    }
};
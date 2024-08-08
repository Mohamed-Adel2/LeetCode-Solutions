class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ret;
        ret.push_back({rStart, cStart});
        int curr = 0;
        while(ret.size() < rows * cols){
            ++curr;
            //right
            for(int i = 0; i <curr; ++i){
                ++cStart;
                if(valid(rows, cols, rStart, cStart))
                    ret.push_back({rStart, cStart});
            }
            //down
            for(int i = 0; i < curr; ++i){
                ++rStart;
                if(valid(rows, cols, rStart, cStart))
                    ret.push_back({rStart, cStart});
            }
            ++curr;
            //left
            for(int i = 0; i < curr; ++i){
                --cStart;
                if(valid(rows, cols, rStart, cStart))
                    ret.push_back({rStart, cStart});
            }
            //up
            for(int i = 0; i < curr; ++i){
                --rStart;
                if(valid(rows, cols, rStart, cStart))
                    ret.push_back({rStart, cStart});
            }
        }
        return ret;
    }

    bool valid(int rows, int cols, int row, int col){
        return(row < rows && row >= 0 && col < cols && col >= 0);
    }
};
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> sum(1002);
        for(int i =0;i < citations.size();i++){
            ++sum[1];
            --sum[citations[i]+1];
        }
        for(int i=1;i<=1000;i++)
            sum[i]+=sum[i-1];
        int ans = 0;
        for(int i=1;i<=1000;i++){
            if(sum[i]>=i)
                ans = i;
        }
        return ans;
    }
};
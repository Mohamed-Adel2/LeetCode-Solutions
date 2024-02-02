class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> need(n,1);
        for(int i = 1;i < n;i++){
            if(ratings[i] > ratings[i-1])
                need[i] = need[i-1] + 1;
        }
        for(int i = n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1])
                need[i] = max(need[i], need[i+1] + 1);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
            ans+=need[i];
        return ans;
    }
};
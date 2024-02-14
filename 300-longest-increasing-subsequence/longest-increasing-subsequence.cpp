class Solution {
public:
    int LISBS(vector<int>& v,int key){
        int l=0,r=v.size()-1;
        int ans=v.size();
        while (l<=r){
            int mid=(l+r)/2;
            if(v[mid]<key){
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }

    vector<int> LIS(vector<int>& v){
        vector<int> piles;
        piles.push_back(v[0]);
        for(int i=1;i<v.size();i++){
            int place= LISBS(piles,v[i]);
            if(place==piles.size())
                piles.push_back(v[i]);
            else
                piles[place]=v[i];
        }
        return piles;
    }
    int lengthOfLIS(vector<int>& nums) {
        return LIS(nums).size();
    }
};
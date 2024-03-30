class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0, temp=0, l=0;
        bool s=false;
        for(int i=0, j=0; j<n; j++) {
            if(mp[nums[j]]==0) l++;
            mp[nums[j]]++;
            while(l>k) {
                mp[nums[i]]--;
                if(mp[nums[i]]<=0) mp[nums[i]]=0, l--;
                i++;
                temp=i;
                s=true;
            }
            if(l==k) {
                while(mp[nums[i]]>1) {
                    mp[nums[i]]--;
                    i++;
                }
                if(s) ans+=i-temp+1;
                else ans+=i+1;
            }
        }
        return ans;
    }
};
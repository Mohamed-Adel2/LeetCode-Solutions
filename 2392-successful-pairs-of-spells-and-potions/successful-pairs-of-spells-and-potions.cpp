class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ret;
        for(int i = 0; i < spells.size(); ++i){
            long long target = (success + spells[i] - 1) / spells[i];
            int lo = 0, hi = potions.size() - 1;
            int ans = potions.size();
            while(lo <= hi){
                int mid = (lo + hi) / 2;
                if(potions[mid] >= target)
                    ans = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
            ret.push_back(potions.size() - ans);
        }
        return ret;
    }
};
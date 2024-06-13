class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> ms;
        for(auto &i : hand)
            ms.insert(i);
        while(!ms.empty()){
            int num = *ms.begin();
            ms.erase(ms.begin());
            for(int i = 1; i < groupSize; ++i){
                if(ms.find(num + i) == ms.end())
                    return false;
                ms.erase(ms.find(num + i));
            }
        }
        return true;
    }
};
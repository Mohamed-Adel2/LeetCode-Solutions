class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int freq[1001] = {};
        for(auto &i : arr1)
            freq[i]++;
        int ptr = 0;
        for(int i = 0; i < arr2.size(); ++i){
            while(freq[arr2[i]]-- > 0)
                arr1[ptr++] = arr2[i];
        }
        for(int i = 0; i < 1001; ++i){
            while(freq[i]-- > 0)
                arr1[ptr++] = i;
        }
        return arr1;
    }
};
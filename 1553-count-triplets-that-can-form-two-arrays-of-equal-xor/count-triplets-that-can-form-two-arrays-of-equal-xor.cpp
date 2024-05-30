class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; ++i) 
            prefix[i + 1] = prefix[i] ^ arr[i];
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
            for (int k = i + 1; k < n; ++k)
                if(prefix[i] == prefix[k + 1])
                    ans += (k - i);
        return ans;
    }
};
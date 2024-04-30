class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<string, long long> freq;
        string mask = "0000000000";
        freq[mask] = 1;
        long long ans = 0;
        for(int i = 0; i < word.size();++i){
            toggle(word[i] - 'a', mask);
            ans += countAnswer(freq, mask);
            ++freq[mask];
        }
        return ans;
    }

    void toggle(int idx, string &mask) {
        mask[idx] = (mask[idx] == '0' ? '1' : '0');
    }

    long long countAnswer(unordered_map<string, long long>& freq, string& mask){
        long long ans = freq[mask];
        for(int i = 0;i<mask.size();++i){
            toggle(i, mask);
            ans += freq[mask];
            toggle(i, mask);
        }
        return ans;
    }
};
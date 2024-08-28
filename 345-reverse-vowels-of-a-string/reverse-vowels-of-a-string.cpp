class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            while(left < right && !isVowel(tolower(s[left])))
                ++left;
            while(right > left && !isVowel(tolower(s[right])))
                --right;
            if(isVowel(tolower(s[left])) && isVowel(tolower(s[right])))
                swap(s[left++], s[right--]);
        }
        return s;
    }

    bool isVowel(char c){
        return(c == 'a' || c == 'e' || c == 'i' || c == 'i' || c == 'u' || c == 'o');
    }
};
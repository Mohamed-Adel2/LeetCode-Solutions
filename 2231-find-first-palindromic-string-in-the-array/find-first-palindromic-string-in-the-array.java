class Solution {
    public String firstPalindrome(String[] words) {
        int sz = words.length;
        for (int i = 0; i < sz; ++i)
            if (isPalindrome(words[i]))
                return words[i];
        return "";

    }
    private boolean isPalindrome(String word) {
        int n = word.length();
        for (int i = 0; i < n; ++i)
            if (word.charAt(i) != word.charAt(n - i - 1))
                return false;
        return true;
    }
}
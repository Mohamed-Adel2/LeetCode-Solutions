class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int ptr1 = 0, ptr2 = s.length() - 1;
        while (ptr1 < ptr2) {
            if (!isCharacter(s.charAt(ptr1)) && !isDigit(s.charAt(ptr1)))
                ++ptr1;
            else if (!isCharacter(s.charAt(ptr2)) && !isDigit(s.charAt(ptr2)))
                --ptr2;
            else if (s.charAt(ptr1++) != s.charAt(ptr2--))
                return false;
        }
        return true;
    }

    boolean isCharacter(char c) {
        return (c >= 'a' && c <= 'z');
    }

    boolean isDigit(char c) {
        return (c >= '0' && c <= '9');
    }
}
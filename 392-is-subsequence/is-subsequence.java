class Solution {
    public boolean isSubsequence(String s, String t) {
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < s.length() && ptr2 < t.length()) {
            if (s.charAt(ptr1) == t.charAt(ptr2)) {
                ++ptr1;
                ++ptr2;
            } else
                ++ptr2;
        }
        return ptr1 == s.length();
    }
}
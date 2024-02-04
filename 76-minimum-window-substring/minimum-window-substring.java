class Solution {
    public String minWindow(String s, String t) {
        int[] tFreq = new int[200];
        int[] sFreq = new int[200];
        int distinct = 0;
        for (int i = 0; i < t.length(); i++) {
            ++tFreq[t.charAt(i)];
            if (tFreq[t.charAt(i)] == 1)
                ++distinct;
        }
        int ptr1 = 0, ptr2 = 0, found = 0, startIdx = -1, endIdx = 1000000;
        while (ptr2 < s.length()) {
            ++sFreq[s.charAt(ptr2)];
            if (sFreq[s.charAt(ptr2)] == tFreq[s.charAt(ptr2)])
                ++found;
            if (found == distinct) {
                while (found == distinct) {
                    --sFreq[s.charAt(ptr1)];
                    if (sFreq[s.charAt(ptr1)] < tFreq[s.charAt(ptr1)])
                        --found;
                    ++ptr1;
                }
                if (endIdx - startIdx > ptr2 - ptr1 + 1) {
                    startIdx = ptr1 - 1;
                    endIdx = ptr2;
                }
            }
            ++ptr2;
        }
        if (startIdx != -1)
            return s.substring(startIdx, endIdx + 1);
        return "";
    }
}
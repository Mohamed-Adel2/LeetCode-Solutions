class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] rFreq = new int[26];
        int[] mFreq = new int[26];
        for (int i = 0; i < ransomNote.length(); i++)
            ++rFreq[ransomNote.charAt(i) - 'a'];
        for (int i = 0; i < magazine.length(); i++)
            ++mFreq[magazine.charAt(i) - 'a'];
        for (int i = 0; i < 26; i++)
            if (rFreq[i] > mFreq[i])
                return false;
        return true;
    }
}
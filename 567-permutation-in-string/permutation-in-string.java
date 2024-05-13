class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        Map<Character, Integer> s1Freq = new HashMap<>(), s2Freq = new HashMap<>();
        for (int i = 0; i < s1.length(); ++i) {
            s1Freq.put(s1.charAt(i), s1Freq.getOrDefault(s1.charAt(i), 0) + 1);
            s2Freq.put(s2.charAt(i), s2Freq.getOrDefault(s2.charAt(i), 0) + 1);
        }
        if (equal(s1Freq, s2Freq))
            return true;
        int sz = s1.length();
        for (int i = sz; i < s2.length(); ++i) {
            s2Freq.put(s2.charAt(i - sz), s2Freq.get(s2.charAt(i - sz)) - 1);
            s2Freq.put(s2.charAt(i), s2Freq.getOrDefault(s2.charAt(i), 0) + 1);
            if (equal(s1Freq, s2Freq))
                return true;
        }
        return false;
    }

    public boolean equal(Map<Character, Integer> s1Freq, Map<Character, Integer> s2Freq) {
        for (Map.Entry<Character, Integer> pair : s1Freq.entrySet()) {
            if (!Objects.equals(s2Freq.getOrDefault(pair.getKey(), 0), pair.getValue()))
                return false;
        }
        return true;
    }
}
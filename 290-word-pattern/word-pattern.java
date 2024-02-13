class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] arr = s.split(" ");
        if (arr.length != pattern.length())
            return false;
        HashMap<Character, String> mp = new HashMap<>();
        for (int i = 0; i < arr.length; ++i) {
            if (mp.containsKey(pattern.charAt(i)) && !mp.get(pattern.charAt(i)).equals(arr[i]))
                return false;
            else if (!mp.containsKey(pattern.charAt(i)) && mp.containsValue(arr[i]))
                return false;
            mp.put(pattern.charAt(i), arr[i]);
        }
        return true;
    }
}
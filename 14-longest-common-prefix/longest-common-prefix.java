class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder ans = new StringBuilder();
        for(int i = 0 ; i < strs[0].length(); i++){
            char c = strs[0].charAt(i);
            for(int j = 1; j < strs.length; j++){
                if(strs[j].length() == ans.length() || strs[j].charAt(i) != c)
                    return ans.toString();
            }
            ans.append(c);
        }
        return ans.toString();        
    }
}
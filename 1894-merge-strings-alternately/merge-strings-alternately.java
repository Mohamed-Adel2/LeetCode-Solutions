class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder str = new StringBuilder();
        int ptr1 = 0, ptr2 = 0;
        boolean first = true;
        while(ptr1 < word1.length() && ptr2 < word2.length()){
            if(first){
                str.append(word1.charAt(ptr1++));
                first = false;
            }
            else{
                str.append(word2.charAt(ptr2++));
                first = true;
            }
        }
        while(ptr1 < word1.length())
            str.append(word1.charAt(ptr1++));
        while(ptr2 < word2.length())
            str.append(word2.charAt(ptr2++));
        return str.toString();
    }
}
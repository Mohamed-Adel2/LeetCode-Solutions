class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= 9; i++) {
            int currNum = 0;
            for (int j = i; j <= 9; j++) {
                currNum *= 10;
                currNum += j;
                if (currNum >= low && currNum <= high)
                    ans.add(currNum);
                else if (currNum > high)
                    break;
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
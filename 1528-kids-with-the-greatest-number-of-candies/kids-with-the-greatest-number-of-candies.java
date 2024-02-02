class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = candies[0];
        Boolean result[] = new Boolean[candies.length];
        for (int i = 0; i < candies.length; i++)
            max = Math.max(max, candies[i]);
        for (int i = 0; i < candies.length; i++) {
            result[i] = (candies[i] + extraCandies >= max);
        }
        return Arrays.asList(result);
    }
}
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        int lose[] = new int[100001];
        for (int i = 0; i < matches.length; i++) {
            if (lose[matches[i][0]] == 0)
                lose[matches[i][0]] = -1;
            if (lose[matches[i][1]] == -1)
                lose[matches[i][1]] = 1;
            else
                lose[matches[i][1]]++;
        }
        ArrayList<Integer> winners = new ArrayList<>();
        ArrayList<Integer> losers = new ArrayList<>();
        for (int i = 1; i < lose.length; i++) {
            if (lose[i] == 1)
                losers.add(i);
            else if (lose[i] <= -1)
                winners.add(i);
        }
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(winners);
        ans.add(losers);
        return ans;
    }
}
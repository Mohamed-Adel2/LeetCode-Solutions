class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Queue<Pair> queue = new ArrayDeque<>();
        Map<String, Boolean> freq = new HashMap<>();
        queue.add(new Pair(startGene, 0));
        freq.put(startGene, true);
        int ans = -1;
        while (!queue.isEmpty()) {
            Pair front = queue.poll();
            if (front.gene.equals(endGene)) {
                ans = front.steps;
                break;
            }
            for (String gene : bank) {
                if (valid(front.gene, gene) && !freq.containsKey(gene)) {
                    freq.put(gene, true);
                    queue.add(new Pair(gene, front.steps + 1));
                }
            }
        }
        return ans;
    }

    boolean valid(String gene1, String gene2) {
        int cnt = 0;
        for (int i = 0; i < gene1.length(); ++i)
            if (gene1.charAt(i) != gene2.charAt(i))
                ++cnt;
        return cnt == 1;
    }
}

class Pair {
    String gene;
    int steps;

    public Pair(String gene, int steps) {
        this.gene = gene;
        this.steps = steps;
    }
}
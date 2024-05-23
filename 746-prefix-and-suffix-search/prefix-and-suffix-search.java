public class WordFilter {
    private TrieNode root;
    private Map<String, Integer> wordToIndex;

    public WordFilter(String[] words) {
        root = new TrieNode();
        wordToIndex = new HashMap<>();

        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            wordToIndex.put(word, i);
            for (int j = 0; j <= word.length(); j++) {
                String suffix = word.substring(j);
                TrieNode node = root;
                for (char c : (suffix + "{" + word).toCharArray()) {
                    node.index = i;
                    if (node.children[c - 'a'] == null) {
                        node.children[c - 'a'] = new TrieNode();
                    }
                    node = node.children[c - 'a'];
                    node.index = i;
                }
            }
        }
    }

    public int f(String prefix, String suffix) {
        TrieNode node = root;
        for (char c : (suffix + "{" + prefix).toCharArray()) {
            if (node.children[c - 'a'] == null) {
                return -1;
            }
            node = node.children[c - 'a'];
        }
        return node.index;
    }

    private class TrieNode {
        TrieNode[] children;
        int index;

        TrieNode() {
            children = new TrieNode[27];
            index = -1;
        }
    }
}
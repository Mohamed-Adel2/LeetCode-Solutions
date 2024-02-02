class Solution {
    public int evalRPN(String[] tokens) {
        int[] arr = new int[tokens.length];
        int ptr = -1;
        int ans = 0;
        for (int i = 0; i < tokens.length; i++) {
            switch (tokens[i]) {
                case "+":
                    arr[ptr - 1] = arr[ptr] + arr[ptr - 1];
                    --ptr;
                    break;
                case "-":
                    arr[ptr - 1] = -arr[ptr] + arr[ptr - 1];
                    --ptr;
                    break;
                case "*":
                    arr[ptr - 1] = arr[ptr] * arr[ptr - 1];
                    --ptr;
                    break;
                case "/":
                    arr[ptr - 1] = arr[ptr - 1] / arr[ptr];
                    --ptr;
                    break;
                default:
                    arr[++ptr] = Integer.parseInt(tokens[i]);
            }
        }
        return arr[ptr];
    }
}
class Solution {
    public int sumSubarrayMins(int[] arr) {
        final int MOD = (int) (1e9 + 7);
        int n = arr.length;
        int left[] = new int[n];
        int right[] = new int[n];
        Stack<Integer> st = new Stack<Integer>();
        // first small number to the right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.peek()] >= arr[i])
                right[st.pop()] = i;
            st.push(i);
        }
        while (!st.empty())
            right[st.pop()] = n;
        // first small number to the left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.peek()] > arr[i])
                left[st.pop()] = i;
            st.push(i);
        }
        while (!st.empty())
            left[st.pop()] = -1;
        // calculate the answer
        long ans = 0;
        for (int i = 0; i < n; i++) {
            long toLeft = (i - left[i] - 1), toRight = (right[i] - i - 1);
            ans = (ans + ((((toLeft + toRight + (toLeft * toRight) + 1) % MOD) * arr[i]) % MOD)) % MOD;
        }
        return (int) ans;
    }
}
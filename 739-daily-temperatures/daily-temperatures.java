class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int []ans = new int[temperatures.length];
        Stack<Integer> st = new Stack<>();
        for(int i = 0;i<temperatures.length;i++){
            while(!st.empty() && temperatures[st.peek()]<temperatures[i]){
                int idx = st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
}
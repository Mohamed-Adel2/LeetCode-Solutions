class MyQueue {

    Stack<Integer> pop, push;

    public MyQueue() {
        pop = new Stack<>();
        push = new Stack<>();
    }

    public void push(int x) {
        push.push(x);
    }

    public int pop() {
        if (pop.empty())
            transfer();
        return pop.pop();
    }

    private void transfer() {
        while (!push.empty())
            pop.push(push.pop());
    }

    public int peek() {
        if (pop.empty())
            transfer();
        return pop.peek();
    }

    public boolean empty() {
        return (push.empty() && pop.empty());
    }
}
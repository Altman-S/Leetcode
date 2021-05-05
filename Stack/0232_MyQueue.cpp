// created by Pi on 5/5/2021
// 用栈实现队列
// input:["MyQueue", "push", "push", "peek", "pop", "empty"]
//       [[], [1], [2], [], [], []]
// output: [null, null, null, 1, 1, false]


class MyQueue {
public:
    stack<int> stack_in;
    stack<int> stack_out;

    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack_in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stack_out.empty()) {  // 当出栈为空的时候，将入栈的元素全部转移到出栈
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int res = stack_out.top();
        stack_out.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res = this->pop();
        stack_out.push(res);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
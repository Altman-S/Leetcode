// craeted by Pi on 5/5/2021
// 用队列实现栈
// input: ["MyStack", "push", "push", "top", "pop", "empty"]
// output: [[], [1], [2], [], [], []]


class MyStack {
public:
    queue<int> que1;  // 原始队列
    queue<int> que2;  // 备份队列

    /** Initialize your data structure here. */
    MyStack() {
    
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que1.size();
        size--;  // 留下最后一个元素pop()出去，相当于栈顶的pop()
        while (size--) {  // 将que1 导入que2，但要留下最后一个元素
            que2.push(que1.front());
            que1.pop();
        }
        int res = que1.front();  // 留下的最后一个元素就是要返回的值
        que1.pop();
        que1 = que2;  // pop后的队列
        while (!que2.empty()) {  // 清空que2
            que2.pop();  
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return que1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
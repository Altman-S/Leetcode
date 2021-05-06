// created by Pi on 6/5/2021
// 逆波兰表达式求值
// input: tokens = ["2","1","+","3","*"]
// output: 9


// 利用栈进行计算
class Solution1 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;  // 存储数字
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();  // 每次遇到符号，取两个数出来算
                stk.pop();
                if (tokens[i] == "+") stk.push(num2 + num1);
                if (tokens[i] == "-") stk.push(num2 - num1);
                if (tokens[i] == "*") stk.push(num2 * num1);
                if (tokens[i] == "/") stk.push(num2 / num1);
            }
            else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
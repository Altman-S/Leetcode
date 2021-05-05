// created by Pi on 5/5/2021
// 有效的括号
// input: s = "()[]{}
// output: true


class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            else if (st.empty() || st.top() != s[i]) return false;  // 右边多括号或者括号不匹配
            else st.pop();
        }
        return st.empty();  // 左边多括号
    }
};
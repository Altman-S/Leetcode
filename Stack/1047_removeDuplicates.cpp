// created by Pi on 6/5/2021
// 删除字符串中的所有相邻重复项
// input: "abbaca"
// output: "ca"


// 运用栈来解决
class Solution1 {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        for (int i = 0; i < S.size(); i++) {
            if (stk.empty() || S[i] != stk.top()) {  
                stk.push(S[i]);
            }
            else {
                stk.pop();
            }
        }
        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution2 {
public:
    string removeDuplicates(string S) {
        string stk;
        for (int i = 0; i < S.size(); i++) {
            if (stk.empty() || S[i] != stk.back()) {  
                stk.push_back(S[i]);
            }
            else {
                stk.pop_back();
            }
        }
        
        return stk;
    }
};
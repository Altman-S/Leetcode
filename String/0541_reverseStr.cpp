// created by Pi on 29/4/2021
// 反转字符串2
// input: s = "abcdefg", k = 2
// output: "bacdfeg"


// 暴力法，库函数  O(N) O(N)
class Solution1 {
public:
    void reverse(string& s, int start, int end) {  // 定义自己的反转函数
        int offset = (end - start + 1) / 2;
        for (int i = start, j = end; i < start + offset; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k - 1 <= s.size() - 1) {  // 剩余字符大于等于k个
                reverse(s, i, i + k - 1);
            }
            else {
                reverse(s, i, s.size() - 1);
            }
        }

        return s;
    }
};
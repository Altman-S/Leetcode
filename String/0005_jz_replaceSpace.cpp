// created by Pi on 29/4/2021
// 替换空格
// input: s = "We are happy."
// output: "We%20are%20happy."


// 申请新数组，直接替换
class Solution1 {
public:
    string replaceSpace(string s) {
        string result = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                result += "%20";
            }
            else {
                result += s[i];
            }
        }

        return result;
    }
};


// 扩充原数组
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0; // 统计空格的个数
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        // 从后先前将空格替换为"%20"
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};
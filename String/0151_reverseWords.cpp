// created by Pi on 30/4/2021
// 翻转字符串里的单词
// input: "the sky is blue"
// output: "blue is sky the"


// 双指针法
class Solution1 {  // 重点在于临界点的确定
public:
    // 反转字符串s的左闭右闭区间[start, end]
    void reverse(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // 利用快慢指针去除多余的空格
    void removeExtraSpaces(string &s) {
        int slowIndex = 0, fastIndex = 0;
        // 去除字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        // 去除中间的空格
        for (; fastIndex < s.size(); fastIndex++) {  // 每个单词之间只有一个空格
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
                continue;
            }
            else {
                s[slowIndex++] = s[fastIndex];
                // slowIndex++;  // 刚好表示字符串的长度
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {  // 去除字符串末尾空格
            s.resize(slowIndex - 1);
        }
        else {
            s.resize(slowIndex);
        }
    }


    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0, end = 0;
        bool entry = false;

        for (int i = 0; i < s.size(); i++) {  // 开始反转单词
            if ((!entry) || (s[i] != ' ' && s[i - 1] == ' ')) {
                start = i;  // 单词起始位置
                entry = true;  // 进入单词区间
            }
            if (entry && s[i] == ' ' && s[i - 1] != ' ') { 
                end = i - 1;  // 单词结束位置
                entry = false;  // 结束单词区间
                reverse(s, start, end);
            }
            if (entry && i == (s.size() - 1) && s[i] != ' ') {
                end = i;  // 单词结束位置
                entry = false;  // 结束单词区间
                reverse(s, start, end);
            }
        }

        return s;
    }
};
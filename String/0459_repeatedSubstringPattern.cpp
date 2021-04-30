// created by Pi on 30/4/2021
// 重复的字字符串
// input: "abab"
// output: True


// KMP算法  O(n) O(n)
class Solution1 {
public:
    void getNext(int* next, const string& s) {  // 得到前缀表
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {  // 存在重复项，很多重复项
            return true;
        }
        return false;
    }
};


// 字符串匹配
class Solution2 {  // 这他喵的怎么想到的？
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
// created by Pi on 30/4/2021
// 左旋转字符串
// input: s = "abcdefg", k = 2
// output: "cdefgab"


// 暴力解法
class Solution1 {
public:
    void reverseOneWord(string &s) {
        char tmp = s[0];
        for (int i = 0; i < s.size() - 1; i++) {
            s[i] = s[i + 1];
        }
        s[s.size() - 1] = tmp;
    }

    string reverseLeftWords(string s, int n) {
        while (n--) {
            reverseOneWord(s);
        }

        return s;
    }
};


// 巧妙的方法
class Solution2 {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        
        return s;
    }
};
// created by Pi on 30/4/2021
// 实现strStr函数
// input: haystack = "hello", needle = "ll"
// output: 2


// 暴力解法  O(n*m) O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() == 0 || haystack.size() < needle.size()) {
            return -1;
        }

        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            if (haystack[i] == needle[0]) {  // 当首字母匹配时，判断整个单词匹不匹配
                for (int m = i, n = 0; n < needle.size(); m++, n++) {
                    if (haystack[m] != needle[n]) {
                        break;
                    }  
                    if (n == needle.size() - 1) {
                        return i;
                    }
                }
                
            }
        }

        return -1;
    }
};


// KMP算法  O(n+m) O(m)
class Solution2 {
public:
    void getNext(int* next, const string& s) {  // 得到-1的next数组
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {  // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) {  // 前后缀不同了
                j = next[j];  // 向前回溯
            }
            if (s[i] == s[j + 1]) {  // 找到相同的前后缀
                j++;
            }
            next[i] = j;  // 将j（前缀的长度）赋给next[i]
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动 
                j++; 
            }
            if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1); 
            }
        }
        return -1;
    }
};
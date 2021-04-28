// created by Pi on 28/4/2021
// 有效的字母异位词
// input: s = "anagram", t = "nagaram"
// output: true


// 哈希表  O(n) O(s)
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};  // 记录26个字母出现的次数
       
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int j = 0; j < t.size(); j++) {
            record[t[j] - 'a']--;
        }
        for (int k = 0; k < 26; k++) { 
            if (record[k] != 0) {
                return false;
            }
        }

        return true;
    }
};


// 排序  O(nlogn) O(logn)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};


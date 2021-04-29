// created by Pi on 29/4/2021
// 赎金信
// input: ransomNote = "a", magazine = "b"
// output: false


// 哈希法1
class Solution1 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mapNote;  // 记录magazine每个字符出现的次数

        for (int i = 0; i < magazine.size(); i++) {
            mapNote[magazine[i]]++;
        }
        for (int j = 0; j < ransomNote.size(); j++) {
            if (mapNote.find(ransomNote[j]) != mapNote.end()) {
                mapNote[ransomNote[j]]--;
                if (mapNote[ransomNote[j]] < 0) {  // 说明不可以由magazine构成
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return true;
    }
};


// 哈希法2
class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};  // 记录magazine每个字符出现的次数

        for (int i = 0; i < magazine.size(); i++) {
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.size(); j++) {
            record[ransomNote[j] - 'a']--;
            if (record[ransomNote[j] - 'a'] < 0) {  // 说明不可以由magazine构成
                return false; 
            }
        }

        return true;
    }
};


// 暴力解法
class Solution3 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < magazine.length(); i++) {
            for (int j = 0; j < ransomNote.length(); j++) {
                // 在ransomNote中找到和magazine相同的字符
                if (magazine[i] == ransomNote[j]) { 
                    ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
                    break;
                }
            }
        }
        // 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
        if (ransomNote.length() == 0) { 
            return true;
        }
        return false;
    }
};

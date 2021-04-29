// created by Pi on 29/4/2021
// 反转字符串
// input: ["h","e","l","l","o"]
// output: ["o","l","l","e","h"]


// 双指针  O(N) O(1) 
class Solution1 {  // 这题太简单了  
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int left = 0, right = s.size() - 1;

        while (left < right) {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};
// created by Pi on 28/4/2021
// 快乐树
// input: 19
// output: true


// 哈希表 unordered_set  O(logn) O(logn)
class Solution1 {
public:
    int getSum(int n) {  // 得到数字上的各位数字的平方和
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10; 
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> record;  // 用来记录平方和是否重复

        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (record.find(sum) != record.end()) {  // 平方和重复，陷入无限循环
                return false;
            }
            else {
                record.insert(sum);
            }
            n = sum;
        }
    }
};


// 快慢指针法  O(logn) O(1)
class Solution2 {
public:
    int getSum(int n) {  // 得到数字上的各位数字的平方和
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10; 
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getSum(n);

        while (fast != 1 && slow != fast) {  // 若slow==fast，则陷入无限循环
            slow = getSum(slow);
            fast = getSum(getSum(fast));
        }
        return fast == 1;
    }
};
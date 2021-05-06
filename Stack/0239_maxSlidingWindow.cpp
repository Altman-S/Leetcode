// created by Pi on 6/5/2021
// 滑动窗口最大值
// input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// output: [3,3,5,5,6,7]


// 暴力解法 超时了
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int slow = 0, fast = k - 1;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            int max = nums[i];
            for (int j = slow; j < fast + 1; j++) {
                if (nums[j] > max) {
                    max = nums[j];
                }
            }
            result.push_back(max);
            slow++;
            fast++;
        }
        return result;
    }
};


// 用deque定义自己的单调队列  O(n) O(k)
class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;
        // 比较当前要弹出的数值是否等于单调队列递减前端元素的数值，如果相等则弹出。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        // 如果push的数值大于单调递减队列后端元素的数值，则弹出后端元素
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }
        // 前端元素是最大值
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int j = 0; j < k; j++) {
            que.push(nums[j]);
        }
        result.push_back(que.front());  // 第一个滑动窗口的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
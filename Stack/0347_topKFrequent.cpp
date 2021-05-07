// created by Pi on 7/5/2021
// 前K个高频元素
// input: nums = [1,1,1,2,2,3], k = 2
// output: [1,2]


// 优先级队列  O(Nlogk) O(N)
class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {     
        unordered_map<int, int> map;  // 统计每个数字出现的频率
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        // 对频率进行排序，定义一个小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (auto it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {  // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }
        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
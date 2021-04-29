// created by Pi on 29/4/2021
// 三数之和
// input: nums = [-1,0,1,2,-1,-4]
// output: [[-1,-1,2],[-1,0,1]]


// 哈希法，算得非常慢  O(n^2)
class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;  // 存储输出结果
        sort(nums.begin(), nums.end());  // 从小到大排序

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {  // 最小的数大于0，和不可能为0
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {  // 避免a的数值重复
                continue;
            }
            unordered_set<int> setRecord;
            for (int j = i + 1; j < nums.size(); j++) {  // 下面这个语句在实际面试的过程中很容易出bug
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {  // 避免b的数值重复
                    continue;  
                }                                      
                int c = 0 - nums[i] - nums[j];
                if (setRecord.find(c) != setRecord.end()) {   
                    result.push_back({nums[i], nums[j], c});  // 执行过程
                    setRecord.erase(c);  // 避免c的重复    // -1 -1 -1 0 0 0 1 1 1 
                }                                        //  a  b
                else {                                   //  a       b
                    setRecord.insert(nums[j]);           //          a b 
                }                                        //          a     b
            }
        }

        return result;
    }
};


// 排序+双指针  O(n^2) O(logn)
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;  // 存储输出结果
        sort(nums.begin(), nums.end());  // 从小到大排序

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return result;  // 最小的数不能大于0
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }                               // 执行过程：
            int left = i + 1;               // -1  -1  -1  0  0  0  1  1  1
            int right = nums.size() - 1;    //  i left                   right
            while (left < right) {          //  i        left   right
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1]) right--; 
                    while (left < right && nums[left] == nums[left + 1]) left++;  // 避免重复
                    right--;  // 找到答案时，双指针收缩
                    left++;
                }              
            }
        }

        return result;
    }
};
// created by Pi on 28/4/2021
// 两数之和
// input: nums = [2,7,11,15], target = 9
// output: [0,1]


// 哈希法  O(N) O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;

        for (int i = 0; i < nums.size(); i++) {
            auto iter = mymap.find(target - nums[i]);
            if (iter != mymap.end()) {
                return {iter->second, i};
            }
            mymap[nums[i]] = i;
        }

        return {};
    }
};
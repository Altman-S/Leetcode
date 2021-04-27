// created by Pi on 27/4/2021
// 移除元素，双指针法    
// O(n) O(1)
// input: nums = [3,2,2,3], val = 3
// output: 2, nums = [2,2]


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;

        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) 
                nums[slowIndex++] = nums[fastIndex];
        }

        return slowIndex;
    }
};
// created by Pi on 27/4/2021
// 二叉查找
// input: nums = [-1,0,3,5,9,12], target = 9    nums = [-1,0,3,5,9,12], target = 2
// output: 4                                    -1


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, left = 0, right = nums.size() - 1;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};
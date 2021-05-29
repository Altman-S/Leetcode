// created by Pi on 29/5/2021
// 给定一个不含重复元素的整数数组num, 得到一个以此数组直接递归构建的最大二叉树 
// input: nums = [3,2,1,6,0,5]
// output: [6,3,5,null,2,0,null,null,1]
// https://mp.weixin.qq.com/s/1iWJV6Aov23A7xCF4nV88w

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 递归
class Solution1 {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // 终止条件 只剩下最后一个节点时
        TreeNode* node = new TreeNode(0);
        if (nums.size() == 1) {
            node->val = nums[0];
            return node;
        }
        // 单层逻辑
        int maxValue = 0;
        int maxValueIndex = 0;
        for (int i = 0; i < nums.size(); i++) {  // 找到最大的元素，进行分割
            if (nums[i] > maxValue) {
                maxValue = nums[i];  // 记录最大的值
                maxValueIndex = i;  // 记录最大值的位置
            }
        }
        node->val = maxValue;
        if (maxValueIndex > 0) {  // 最大值所在的下表左区间 构造左子树 [0, maxValueIndex)
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(newVec);
        }
        if (maxValueIndex < nums.size() - 1) {  // 最大值所在的下表右区间 构造右子树 [maxValueIndex + 1, end())
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }
        return node;
    }
};
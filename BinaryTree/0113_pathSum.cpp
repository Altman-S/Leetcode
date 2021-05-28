// created by Pi on 28/5/2021
// 路径总和2
// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
// input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// output: [[5,4,11,2],[5,8,4,5]]


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


// 递归+回溯 DFS 前序遍历
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    // 递归函数不需要返回值，因为我们要遍历整个树
    void traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) {  // 遇到了叶子节点切找到了和为sum的路径
            result.push_back(path);
            return;
        }
        if (!cur->left && !cur->right) return;  // 遇到叶子节点而没有找到合适的边，直接返回
        if (cur->left) {
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);  // 递归
            count += cur->left->val;  // 回溯
            path.pop_back();  // 回溯
        }
        if (cur->right) {
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);  // 递归
            count += cur->right->val;  // 回溯
            path.pop_back();  // 回溯
        }
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {  
        result.clear();
        path.clear();
        if (root == NULL) return result;
        path.push_back(root->val);  // 把根节点放进路径
        traversal(root, targetSum - root->val);
        return result;
    }
};
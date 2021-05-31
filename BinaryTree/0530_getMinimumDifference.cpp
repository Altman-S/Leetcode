// created by Pi on 30/5/2021
// 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
// input: 1
//         \
//          3
//         /
//        2
// output: 1
// https://mp.weixin.qq.com/s/Hwzml6698uP3qQCC1ctUQQ

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

// 迭代 中序遍历 stack
class Solution1 {
public:
    int getMinimumDifference(TreeNode* root) {  // 中序遍历
        int result = INT_MAX;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;  // 记录前一节点
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;  // 左
            }
            else {
                cur = st.top();  // 中
                st.pop();
                if (pre != NULL && abs(pre->val - cur->val) < result) {
                    result = abs(pre->val - cur->val);
                }
                pre = cur;  // 保存前一个访问的节点
                cur = cur->right;  // 右
            }
        }
        return result;
    }
};

// 递归 中序遍历 BST
class Solution2 {
private:
    int result = INT_MAX;
    TreeNode* pre;
    void traversal(TreeNode* cur) {
        // 终止条件
        if (cur == NULL) return;
        // 单层逻辑
        traversal(cur->left);  // 左
        if (pre != NULL) {
            result = min(result, cur->val - pre->val);  // 中
        } 
        pre = cur;
        traversal(cur->right);  // 右
    }
public:
    int getMinimumDifference(TreeNode* root) {  // 中序遍历
        traversal(root);
        return result;
    }
};
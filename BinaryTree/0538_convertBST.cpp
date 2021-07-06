// created by Pi on 29/6/2021
// 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
// 使每个节点node的新值等于原树中大于或等于node.val的值之和。
// input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
// output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
// https://leetcode-cn.com/problems/convert-bst-to-greater-tree/

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
private:
    int pre;  // 记录前一个节点的数值
    void traversal(TreeNode* cur) {  // 反中序
        // 终止条件
        if (cur == nullptr) return;
        // 单层逻辑
        traversal(cur->right);  // 右
        cur->val += pre;  // 中
        pre = cur->val;
        traversal(cur->left);  // 左
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};

// 迭代 利用栈
class Solution2 {
private:
    int pre;  // 记录前一个节点的数值
    void traversal(TreeNode* root) {  // 反中序
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->right;  // 右
            }
            else {
                cur = st.top();
                st.pop();
                cur->val += pre;  // 中
                pre = cur->val;
                cur = cur->left;  // 左
            }
        }
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};
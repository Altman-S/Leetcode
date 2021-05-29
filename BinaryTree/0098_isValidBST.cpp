// created by Pi on 29/5/2021
// 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
// input: 2
//       / \
//      1   3
// output: true
// https://mp.weixin.qq.com/s/8odY9iUX5eSi0eRFSXFD4Q

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

// 递归 中序遍历 vector
class Solution1 {
private:
    vector<int> vec;
    void traversal(TreeNode* root) {  // 中序遍历，从小到大
        if (root == NULL) return;
        traversal(root->left);  // 左
        vec.push_back(root->val); // 将二叉搜索树转换为有序数组
        traversal(root->right);  // 右
    }
public:
    bool isValidBST(TreeNode* root) {
        vec.clear(); // 不加这句在leetcode上也可以过，但最好加上
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            // 注意要小于等于，搜索树里不能有相同元素
            if (vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
};

// 递归 中序遍历
class Solution2 {
public:
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {
        // 终止条件
        if (root == NULL) return true;
        // 单层逻辑
        bool left = isValidBST(root->left);  // 左
        if (pre != NULL && pre->val >= root->val) return false;  // 中
        pre = root;  // 记录前一个节点
        bool right = isValidBST(root->right);  // 右
        return left && right;
    }
};

// 迭代 中序遍历
class Solution3 {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;  // 记录前一个节点
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;  // 左
            }
            else {
                cur = st.top();  // 中
                st.pop();
                if (pre != NULL && cur->val <= pre->val) return false;
                pre = cur;  // 保存前一个访问的节点
                cur = cur->right;  // 右
            }
        }
        return true;
    }
};
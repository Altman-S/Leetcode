// created by Pi on 25/5/2021
// 平衡二叉树
// input: root = [3,9,20,null,null,15,7]
// output: true


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
class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);  // 左
        if (leftDepth == -1) return -1;  // 灵魂
        int rightDepth = getDepth(node->right);  // 右
        if (rightDepth == -1) return -1;
        int result;
        if (abs(leftDepth - rightDepth) > 1) {
            result = -1;
        }
        else {
            result = 1 + max(leftDepth, rightDepth);  // 中
        }
        return result;
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false : true;
    }
};


// 迭代
class Solution2 {
public:
    int getDepth(TreeNode* node) {  //  迭代后序遍历，记录每个节点的深度
        stack<TreeNode*> st;
        if (node != NULL) st.push(node);
        int depth = 0;  // 记录深度
        int result = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);  // 中
                st.push(NULL);
                depth++;
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);  // 左
            }
            else {
                st.pop();
                node = st.top();
                st.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return true;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();  // 中
            st.pop();
            if (abs(getDepth(node->left) - getDepth(node->right)) > 1) return false;
            if (node->right) st.push(node->right);  // 右
            if (node->left) st.push(node->left);  // 左
        }
        return true;
    }
};
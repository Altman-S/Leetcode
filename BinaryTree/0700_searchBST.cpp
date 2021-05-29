// created Pi on 29/5/2021
// 给定二叉搜索树(BST)的根节点和一个值。你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。
// 如果节点不存在，则返回NULL。
// input:  4     2
//        / \
//       2   7
//      / \
//     1   3
// output:  2     
//         / \   
//        1   3
// https://mp.weixin.qq.com/s/vsKrWRlETxCVsiRr8v_hHg

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

// 递归 前序遍历 DFS
class Solution1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {  // 前序遍历，DFS
        // 终止条件
        if (root == NULL) return root;
        // 单层逻辑
        if (root->val == val) return root;  // 中
        if (root->val > val) {  // 左
            return searchBST(root->left, val);
        }
        if (root->val < val) {  // 右
            return searchBST(root->right, val);
        }
        return NULL;
    }
};

// 迭代
class Solution2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {  // 迭代
        while (root != NULL) {
            if (root->val == val) return root;
            else if (root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
        }
        return NULL;
    }
};
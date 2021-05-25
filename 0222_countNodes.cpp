// created by Pi on 25/5/2021
// 完全二叉树的节点个数
// input: root = [1,2,3,4,5,6]
// output: 6


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


// 递归 后序遍历 DFS
class Solution1 {
public:
    int getNodesnum(TreeNode* node) {
        if (node == NULL) return 0;
        int leftNum = getNodesnum(node->left);  // 左
        int rightNum = getNodesnum(node->right);  // 右
        int treeNum = 1 + leftNum + rightNum;  // 中
        return treeNum;
    }
    int countNodes(TreeNode* root) {
        return getNodesnum(root);
    }
};


// 迭代 层序遍历 BFS 写了太多次了，没必要再写了
class Solution2 {
public:
    
};
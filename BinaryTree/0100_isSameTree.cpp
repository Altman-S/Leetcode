// created by Pi on 27/5/2021
// 相同的树
// input: p = [1,2,3], q = [1,2,3]
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
class Solution1 {
public:
    bool compare(TreeNode* tree1, TreeNode* tree2) {
    	// 每一层的逻辑
        if (tree1 == NULL && tree2 != NULL) return false;
        else if (tree1 != NULL && tree2 == NULL) return false;
        else if (tree1 == NULL && tree2 == NULL) return true;
        else if (tree1->val != tree2->val) return false;
        // 下面开始递归
        bool leftSide = compare(tree1->left, tree2->left);
        bool rightSide = compare(tree1->right, tree2->right);
        bool isSame = leftSide && rightSide;
        return isSame;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
}; 
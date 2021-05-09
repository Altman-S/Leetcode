// created by Pi on 9/5/2021
// 二叉树的中序遍历
// input: root = [1,null,2,3]
// output: [1,3,2]


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
    void intraversal(TreeNode* cur, vector<int>& res) {
        if (cur == NULL) return;
        intraversal(cur->left, res);
        res.push_back(cur->val);
        intraversal(cur->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        intraversal(root, result);
        return result;
    }
};


// 迭代
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
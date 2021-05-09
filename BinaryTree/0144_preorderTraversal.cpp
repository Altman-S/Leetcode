// created by Pi on 9/5/2021
// 二叉树的前序的遍历
// input: root = [1,null,2,3]
// output: [1,2,3]


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

// 递归解法  O(n) O(n)
class Solution1 {
public:
    void pretraversal(TreeNode* cur, vector<int>& res) {  // 前序遍历
        if (cur == NULL) return;
        res.push_back(cur->val);
        pretraversal(cur->left, res);
        pretraversal(cur->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        pretraversal(root, result);
        return result;
    }
};


// 迭代  O(n) O(n)
class Solution2 {  // 这个方法不好想出来
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node != nullptr) {  // 模仿
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }
};
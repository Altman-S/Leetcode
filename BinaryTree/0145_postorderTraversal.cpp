// created by Pi on 9/5/2021
// 二叉树的后续遍历
// input: [1,null,2,3] 
// output: [3,2,1]


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
    void posttraversal(TreeNode* cur, vector<int>& res) {
        if (cur == NULL) return;
        posttraversal(cur->left, res);
        posttraversal(cur->right, res);
        res.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        posttraversal(root, result);
        return result;
    }
};


// 迭代
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};


// 迭代第2种方法
class Solution3 {  // 中左右 -> 中右左 -> 左右中
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();  // 中
            st.pop();
            if (node != NULL) {
                result.push_back(node->val);
            }
            else {
                continue;
            }
            st.push(node->left);  // 左 先进后出
            st.push(node->right);  // 右
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
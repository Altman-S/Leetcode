// created by Pi on 27/5/2021
// 二叉树的所有路径
// input:   1
//        /   \
//       2     3
//        \
//         5
// output: ["1->2->5", "1->3"]


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


// 递归 回溯
class Solution1 {
public:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);
        // 这才到了叶子节点
        if (cur->left == NULL && cur->right == NULL) {
            string spath;
            for (int i = 0; i < path.size() - 1; i++) {
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            result.push_back(spath);
        }
        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();  // 回溯
        }
        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back();  // 回溯
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        traversal(root, path, result);
        return result;
    }
};


// 迭代
class Solution2 { 
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;  // 保存结果
        stack<TreeNode*> nodeSt;  // 保存遍历的节点
        stack<string> pathSt;  // 保存遍历的路径 节点和路径一起操作
        if (root == NULL) return result;
        nodeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!nodeSt.empty()) {
            TreeNode* node = nodeSt.top();  // 取出最上面的节点
            nodeSt.pop();
            string path = pathSt.top();  // 取出节点对应的路径
            pathSt.pop();
            if (node->left == NULL && node->right == NULL) {
                result.push_back(path);
            }
            if (node->left) {
                nodeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
            if (node->right) {
                nodeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
        }
        return result;
    }
};
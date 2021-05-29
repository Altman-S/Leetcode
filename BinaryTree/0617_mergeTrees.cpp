// created by Pi on 29/5/2021
// 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
// input: Tree 1                     Tree 2                  
//          1                         2                             
//         / \                       / \                            
//        3   2                     1   3                        
//       /                           \   \                      
//      5                             4   7    
// output:   3
// 	        / \
//  	   4   5
//   	  / \   \ 
//  	 5   4   7
// https://mp.weixin.qq.com/s/3f5fbjOFaOX_4MXzZ97LsQ

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 结束条件
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        // 单层逻辑
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

// 层序遍历
class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            node1->val += node2->val;  // 此时两个节点一定不为空，val相加
            // 如果两棵树左节点都不为空，加入队列
            if (node1->left && node2->left) {
                que.push(node1->left);
                que.push(node2->left);
            }
            // 如果两棵树右节点都不为空，加入队列
            if (node1->right && node2->right) {
                que.push(node1->right);
                que.push(node2->right);
            }
            // 当root1的左节点为空,root2左节点不为空，就赋值过去
            if (!node1->left && node2->left) {
                node1->left = node2->left;
            }
            // 当root1的右节点为空,root2右节点不为空，就赋值过去
            if (!node1->right && node2->right) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};

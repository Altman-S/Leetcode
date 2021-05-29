// created by Pi on 29/5/2021
// 构造二叉树
// 根据一棵树的中序遍历与后序遍历构造二叉树。
// input: 中序遍历 inorder = [9,3,15,20,7]  后序遍历 postorder = [9,15,7,20,3]
// output:  3
//         / \
//        9  20
//          /  \
//         15   7
// https://mp.weixin.qq.com/s/7r66ap2s-shvVvlZxo59xg

// 第一步：如果数组大小为零的话，说明是空节点了。
// 第二步：如果不为空，那么取后序数组最后一个元素作为节点元素。
// 第三步：找到后序数组最后一个元素在中序数组的位置，作为切割点
// 第四步：切割中序数组，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）
// 第五步：切割后序数组，切成后序左数组和后序右数组
// 第六步：递归处理左区间和右区间

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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        // 第一步
        if (postorder.size() == 0) return NULL;
        // 第二步：后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);
        if (postorder.size() == 1) return root;  // 叶子节点
        // 第三步：找切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        } 
        // 第四步：切割中序数组，得到 中序左数组和中序右数组  
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);  // [0, delimiterIndex)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());  // [delimiterIndex + 1, end)
        // 第五步：切割后序数组，得到 后序左数组和后序右数组
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());  // [0, leftInorder.size)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());  // [leftInorder.size(), end)
        // 第六步
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};
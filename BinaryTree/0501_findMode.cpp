// created by Pi on 30/5/2021
// 给定一个有相同值的二叉搜索树（BST），找出BST中的所有众数（出现频率最高的元素）。
// input: 1
//         \
//          2
//         /
//        2
// output: [2]
// https://mp.weixin.qq.com/s/KSAr6OVQIMC-uZ8MEAnGHg

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

// 递归1
class Solution1 {  // 当二叉树是普通树时
private:
    void searchBST(TreeNode* cur, unordered_map<int, int>& map) {  // 前序遍历
        // 终止条件
        if (cur == NULL) return;
        // 单层逻辑
        map[cur->val]++;  // 统计元素的频率
        searchBST(cur->left, map);  // 左
        searchBST(cur->right, map);  // 右
    }
    bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {  // 判断频率大小
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;  // key:元素，value:出现频率
        vector<int> result;
        if (root == NULL) return result;
        searchBST(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);  // 给频率排个序
        result.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second) {  
                result.push_back(vec[i].first);  // 取最高的放到result数组中
            }
            else {
                break;
            }
        }
        return result;
    }
};

// 递归2
class Solution2 {  // 当二叉树是搜索树时
private:
    int maxCount;  // 最大频率
    int count;  // 统计频率
    TreeNode* pre;
    vector<int> result;
    void searchBST(TreeNode* cur) {  // 中序遍历
        // 终止条件
        if (cur == NULL) return;
        // 单层逻辑
        searchBST(cur->left);
        if (pre == NULL) {  // 第一个节点
            count = 1;
        }
        else if (pre->val == cur->val) {  // 与前一个节点数值相同
            count++;
        }
        else {  // 与前一个节点数值不同
            count = 1;
        }
        pre = cur;  // 记录前一节点
        if (count == maxCount) {  // 如果和最大值相同，放进result中
            result.push_back(cur->val);
        }
        if (count > maxCount) {  // 如果计数大于最大值频率
            maxCount = count;
            result.clear();  // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
            result.push_back(cur->val);
        }
        searchBST(cur->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        TreeNode* pre = NULL;
        result.clear();
        searchBST(root);
        return result;
    }
};

// 迭代
class Solution3 {  // 迭代 中序遍历 因为是BST
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* pre = NULL;
        TreeNode* cur = root;      
        int count = 0;  // 记录频率
        int maxValue = 0;  // 记录频率最大值
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;  // 左
            }
            else {
                cur = st.top();  // 中
                st.pop(); 
                if (pre == NULL) {
                    count = 1;
                }
                else if (pre->val == cur->val) {
                    count++;
                }
                else {
                    count = 1;
                }
                pre = cur;  // 记录前一节点
                if (count == maxValue) {
                    result.push_back(cur->val);
                }
                if (count > maxValue) {
                    maxValue = count;
                    result.clear();
                    result.push_back(cur->val);
                }
                cur = cur->right;  // 右
            }
        }
        return result;
    }
};
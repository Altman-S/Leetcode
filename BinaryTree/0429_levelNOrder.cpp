// created by Pi on 14/5/2021
// N叉树的层序遍历
// input: root = [1,null,3,2,4,null,5,6]
// output: [[1],[3,2,4],[5,6]]


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


// 队列层次遍历
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            vector<int> vec;  // 记录每一层的数据
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (int j = 0; j < node->children.size(); j++) {
                    que.push(node->children[j]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
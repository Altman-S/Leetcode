// created by Pi on 18/5/2021
// N叉树的最大深度
// input: root = [1,null,3,2,4,null,5,6]
// output: 3


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


// 层序遍历
class Solution1 {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        int depth = 0;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                for (int j = 0; j < node->children.size(); j++) {
                    que.push(node->children[j]);
                }
            }
            depth++;
        }
        return depth;
    }
};


// 递归
class Solution2 {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int depth = 0;
        for (int i = 0; i < root->children.size(); i++) {
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth + 1;
    }
};
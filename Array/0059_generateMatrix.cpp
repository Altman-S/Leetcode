// created by Pi on 27/4/2021
// 螺旋矩阵2，模拟行为
// input: n = 3
// output: [[1,2,3],[8,9,4],[7,6,5]]


// 按层模拟  O(n^2) O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));  // 定义一个全0的二位数组
        int startx = 0, starty = 0;  // 定义每一圈循环的起始位置
        int loop = n / 2;  // 循环的圈数
        int mid = n / 2;  // 矩阵中间的位置
        int count = 1;  // 用来给矩阵的每一个空格赋值
        int offset = 1;  // 控制每一条边遍历的长度
        int i, j;

        while (loop--) {
            i = startx;
            j = starty;
            // 开始四周的循环
            for (j = starty; j < starty + n - offset; j++) {  // left->right
                res[startx][j] = count++;
            }
            for (i = startx; i < startx + n - offset; i++) {  // top->bottom
                res[i][j] = count++;
            }
            for (; j > starty; j--) {  // right->left
                res[i][j] = count++;
            }
            for (; i > startx; i--) {  // bottom->top
                res[i][j] = count++;
            }
            // 第二圈开始的时候
            startx++;
            starty++;
            // 控制每一条边遍历的长度
            offset += 2;
        }

        if (n % 2) {  // n为奇数时，需要单独给矩阵最中间的位置赋值
            res[mid][mid] = count; 
        }
        
        return res;
    }
};


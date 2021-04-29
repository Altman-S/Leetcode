// created by Pi on 29/4/2021
// 四数相加2
// input: A = [1, 2] B = [-2,-1] C = [-1, 2] D = [0, 2]
// output: 2


// 哈希法  O(n^2) O(n^2)
class Solution1 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mapAB;  // key:a+b的值，value:a+b出现的次数
        int count = 0;  // a+b+c+d=0出现的次数

        for (int i = 0; i < nums1.size(); i++) {  // 遍历A、B数组，统计出现的和以及次数
            for (int j = 0; j < nums2.size(); j++) {
                mapAB[nums1[i] + nums2[j]]++;
            }
        }
        for (int p = 0; p < nums3.size(); p++) {  // 如果0-c-d=0在mapAB出现，count加上对应的value值
            for (int q = 0; q < nums4.size(); q++) {
                if (mapAB.find(0 - nums3[p] - nums4[q]) != mapAB.end()) {
                    count += mapAB[0 - nums3[p] - nums4[q]];  
                }
            }
        }
        return count;
    }
};
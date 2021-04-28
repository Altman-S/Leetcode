// created by Pi on 28/4/2021
// 两个数组的交集
// input: nums1 = [1,2,2,1], nums2 = [2,2]
// output: [2]
// 如果哈希值比较少、特别分散、跨度非常大，使用数组就造成空间的极大浪费。
// 此时就要使用另一种结构体set了，我们使用unordered_set


// 哈希法  O(m+n) O(m+n)
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        unordered_set<int> result_set;

        for (int num : nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }

        return vector<int>(result_set.begin(), result_set.end()); 
    }
};


// 排序+双指针  O(mlogm) O(nlogn)
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        int index1 = 0, index2 = 0;
        vector<int> result_set;

        while (index1 < length1 && index2 < length2) {
            int num1 = nums1[index1], num2 = nums2[index2];
            if (num1 == num2) {
                // 保证加入元素的唯一性
                if (!result_set.size() || num1 != result_set.back()) {
                    result_set.push_back(num1);
                }
                index1++;
                index2++;
            } else if (num1 < num2) {
                index1++;
            } else {
                index2++;
            }
        }

        return result_set;
    }
};

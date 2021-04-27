// created by Pi on 27/4/2021
// 长度最小的子数组
// input: target = 7, nums = [2,3,1,2,4,3]
// output: 2


// 暴力解法  O(n^2) O(1)
class Solution1 {   
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;  // 结果
        int sum = 0;  // 子序列之和
        int minlength = 0;  // 子序列最小长度

        for (int i = 0; i < nums.size(); i++) {
            sum = 0;  // 每一次遍历
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= target) {
                    minlength = j - i + 1;
                    result = result < minlength ? result : minlength;
                    break;
                }
            }
        }

        return result == INT32_MAX ? 0 : result;
    }
};


// 前缀和+二分查找  O(nlogn) O(n)
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    	int result = INT32_MAX;
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        
        // 得到前缀和  sums[0]=0  sums[1]=nums[0]
        for (int i = 1; i <= n; i++) {
        	sums[i] = sums[i - 1] + nums[i - 1];
        }
        
        // 进行二分查找
        for (int j = 1; j <= n; j++) {
        	int s = target + sums[j - 1];
        	auto bound = lower_bound(sums.begin(), sums.end(), s);
        	if (bound != sums.end()) {
        		result = min(result, static_cast<int>((bound - sums.begin()) - (j - 1)));
        	}
        }

        return result == INT32_MAX ? 0 : result;
    }
};


// 滑动窗口  O(n) O(1)
class Solution3 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;  // 结果
        int sum = 0;  // 子序列之和
        int sublength = 0;  // 子序列最小长度
        int i = 0;  // 滑动窗口起始位置

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            
            // 时时刻刻更新滑动空间的大小
            while (sum >= target) {
                sublength = j - i + 1;
                result = result < sublength ? result : sublength;
                sum -= nums[i++];
            }
        }

        return result == INT32_MAX ? 0 : result;
    }
};




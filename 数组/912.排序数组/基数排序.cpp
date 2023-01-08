class Solution {
public:
    void radixSort(vector<int> &nums, vector<int> &tmp, int divisor) {
        int n = nums.size();
        vector<int> counts(10, 0);
        for(int i = 0; i<n; i++) {
            // x 获得nums[i]的每一位上的数字
            int x = (nums[i] / divisor) % 10;
            // counts记录每一位出现的次数
            ++counts[x];
        }
        // 前缀和，与计数排序的C数组相同
        for(int i = 1; i<=9; i++) {
            counts[i] += counts[i-1];
        }
        // 将counts数组中的信息存放到tmp数组中
        // 等于在计数排序中将C数组放到B数组中
        for(int i=n-1; i>=0; --i) {
            int x = (nums[i] / divisor) % 10;
            // -1的目的是让tmp数组的下标能从0开始
            tmp[counts[x] - 1] = nums[i];
            counts[x]--;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // 基数排序要保证nums数组中每一个数都为正数
        for(int i = 0; i<n; i++) {
            // nums数组中最小的元素为 -5 * 10^4
            nums[i] += 50000;
        }

        // 取到nums数组中最大的元素，用于获得maxLen
        int maxNums = nums[0];
        for(int i = 0; i<n; i++) {
            if(nums[i] > maxNums) maxNums = nums[i];
        }
        int num = maxNums, maxLen = 0;
        while(num) {
            ++maxLen;
            num /= 10;
        }

        // divisor取值为10^n  n = 0,1,2....,maxLen
        int divisor = 1;
        // tmp数组临时存放排序好的数组
        vector<int> tmp(n, 0);
        for(int i = 0; i<maxLen; i++) {
            radixSort(nums, tmp, divisor);
            swap(tmp, nums);
            divisor *= 10;
        }

        // 减去一开始加上的数
        for(int i = 0; i<n; i++) {
            nums[i] -= 50000;
        }

        return nums;
    }
};

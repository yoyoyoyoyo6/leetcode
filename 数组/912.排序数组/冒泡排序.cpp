class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // bubbleSort
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            bool falg = false;
            // j的范围不断缩小,缩小比较范围
            for(int j = 0; j < n - 1 - i; j++) {
                // 前后比大小
                // 所以i的最大是到n-2
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    falg = true;
                }
            }
            // falg == false时说明此时数组已经为正序，无需继续遍历，直接跳出循环
            if(falg == false) break;
        }
        return nums;
    }
};

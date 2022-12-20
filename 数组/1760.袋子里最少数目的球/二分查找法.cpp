class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // left为下界1，right为上界（数组中最大元素的位置）
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while (left <= right) {
            int y = (left + right) / 2;
            // 存放当前二分窗口内的操作数总和
            long long ops = 0;
            for (int x: nums) {
                // x - 1 的目的是当nums[i]小于等于y时不用操作，即为ops为0
                ops += (x - 1) / y;
            }
            // 如果ops<=maxOperations，则将上界缩小
            if (ops <= maxOperations) {
                ans = y;
                right = y - 1;
            }
            // 反之则将下界增大
            else {
                left = y + 1;
            }
        }
        return ans;
    }
};

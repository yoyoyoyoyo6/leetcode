class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        vector<int> newNums(n/2);
        for(int i=0; i<newNums.size(); i++) {
            // 对于满足 0 <= i < n / 2 的每个 偶数 下标 i ，将 newNums[i] 赋值 为 min(nums[2 * i], nums[2 * i + 1]) 。
            if(i % 2 == 0) {
                newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
            // 对于满足 0 <= i < n / 2 的每个 奇数 下标 i ，将 newNums[i] 赋值 为 max(nums[2 * i], nums[2 * i + 1]) 。
            else {
                newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
        }
        return minMaxGame(newNums);
    }
};

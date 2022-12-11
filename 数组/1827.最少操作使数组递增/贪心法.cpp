class Solution {
public:
    int minOperations(vector<int>& nums) {
        int pre = nums[0] - 1, res = 0;
        for(int num : nums) {
            // 如果后一个数要大于前一个数(单调递增)，则res += 0
            // 反之，res += 就为后一个数要加多少才大于前一个数
            // 加一的目的是使得后一个数增加后是严格大于前一个数
            pre = max(pre + 1, num);
            res += pre - num;
        }
        return res;
    }
};

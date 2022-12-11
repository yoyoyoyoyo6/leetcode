class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i > 0 && nums[i-1] >= nums[i]) {
                ans += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                count++;
            }
        }
        return count;
    }
};

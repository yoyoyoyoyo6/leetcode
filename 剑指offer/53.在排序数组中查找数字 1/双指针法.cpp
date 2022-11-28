class Solution {
public:
    int binarySearch(vector<int> &nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while(left <= right) {
            int mid = (right + left) / 2;
            if(nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false) - 1;
        if(leftIndex <= rightIndex && rightIndex < nums.size() && nums[leftIndex] == target && nums[rightIndex] == target) {
                 return rightIndex - leftIndex + 1;
        }
        return 0;
    }
};

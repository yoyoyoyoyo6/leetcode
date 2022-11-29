class Solution {
public:
    int binarySearch(vector<int> &nums, int target, bool lower) {
        // 该函数核心：构建一个窗口，窗口中存放的值都为target，left就指向窗口的左界(第一个target)，
        //            right指向左界(最后一个target的下一个元素)
        // 那么问题就为如何得到这个窗口
        // 该函数实现的是找到窗口的界，那么问题继续转化为如何区分左右界
        // 为区分左右界，创建了一个lower变量，如果为左界，则取到当前的元素，即为当nums[mid] >= target时
        //      如果为右界，则为nums[mid] > target
        // 所以在求左界时，lower的传参为true，求右界时，传参为false
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while(left <= right) {
            int mid = (right + left) / 2;
            // 增加一个lower变量是为了能得到当前元素
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
        // 求右界时，要-1，与下标对应
        int rightIndex = binarySearch(nums, target, false) - 1;
        if(leftIndex <= rightIndex && rightIndex < nums.size() && 
            nums[leftIndex] == target && nums[rightIndex] == target) {
                 return rightIndex - leftIndex + 1;
            }
        return 0;
    }
};

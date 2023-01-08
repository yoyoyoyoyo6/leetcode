class Solution {
public:

    void quickSort(vector<int> &nums, int startIndex, int endIndex) {
        // 递归停止条件
        if(startIndex >= endIndex) return;

        // 随机化快速排序
        // 不生成随机数则较少数据可能能过，
        //      当数组已经有序，普通快速排序的时间复杂度为O(n^2),所以当数组为1...50000且有序时，超时
        // 生成的随机数范围在startIndex到endIndex之间
        int x = rand() % (endIndex - startIndex + 1) + startIndex;
        // 交换主元和随机生成的元素的位置
        swap(nums[startIndex], nums[x]);
        // 将nums数组在该范围中的第一个元素设置为主元
        int firstNum = nums[startIndex];

        int l = startIndex, r = endIndex;
        while(l < r) {

            // 从数组后面找第一个小于firstNum的放在前面
            while(l < r && nums[r] >= firstNum) --r;
            // 用赋值放前面
            if(l < r) {
                nums[l] = nums[r];
            }

            // 从数组前面找第一个大于firstNum的放在后面
            while(l < r && nums[l] <= firstNum) ++l;
            // 用赋值放后面
            if(l < r) {
                nums[r] = nums[l];
            }
        }
        // 主元最后要放在数组的开头
        nums[l] = firstNum;
        // 递归对两个两个范围继续解决
        quickSort(nums, startIndex, l - 1);
        quickSort(nums, l + 1, endIndex);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }
};

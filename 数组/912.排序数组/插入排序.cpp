class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // insertSort
        int n = nums.size();
        for(int i = 1; i<n; i++) {
            if(nums[i] > nums[i-1]) continue;

            // 二分查找，r左边的数都要小于等于nums[i],右边的数都要大于nums[i]
            // so nums[r] <= nums[i]
            // 所以把nums[i]插入到 r + 1 的位置上
            int l = 0, r = i - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(nums[i] < nums[mid]) r = mid - 1;
                else l = mid + 1;
            }

            // nums[i]要插入的位置
            int index = r + 1;
            // 将nums[i]的元素临时存放到tmp中，防止覆盖后找不着
            int tmp = nums[i];
            // 将index + 1到i-1的元素向前挪一位，nums[i]会被覆盖
            for(int k = i; k>=index+1; --k) {
                nums[k] = nums[k-1];
            }
            // 最后将nums[index]的位置插入nums[i];
            nums[index] = tmp;
        }
        return nums;
    }
};

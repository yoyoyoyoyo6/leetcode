class Solution {
public:
    int randomized_select(vector<int>& nums, int left, int right, int k) {
        int i = left, j = right;
        int x = rand() % (right - left + 1) + left;
        swap(nums[x], nums[right]);
        // 逆序排序，使得能从头开始找k的位置
        // == partition的逆序版
        while(i < j) {
            while(i < j && nums[i] >= nums[right]) i++;
            while(i < j && nums[j] <= nums[right]) j--;
            swap(nums[i], nums[j]);
        }
        swap(nums[right], nums[i]);
        // 选择算法
        // left到i之间的元素（包括i）为i - left + 1
        // i - left 就等于i，所以k要减一或者i + 1
        // if(i < k - 1) or if(i + 1> k)

        // i + 1 < k 则说明k指向的数在右边的数组，递归右数组
        if(i + 1 < k) return randomized_select(nums, i + 1, right, k);
        // 反之递归左数组
        if(i > k - 1) return randomized_select(nums, left, i - 1, k);
        
        // if(i == k - 1) return nums[i]
        return nums[i];
    } 

    int findKthLargest(vector<int>& nums, int k) {
        return randomized_select(nums, 0, nums.size()-1, k);
    }
};

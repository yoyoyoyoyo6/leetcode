class Solution {
public:

    void shellSort(vector<int> &nums, int gap, int i) {
        // 插入排序的思路
        int j, tmp = nums[i];
        // 匹配成组的元素如果后面的小于前面的则前后相互交换（把小的扔前面）
        // i的变化能遍历完当前gap间隔下的各个组
        for(j = i - gap; j >= 0 && tmp < nums[j]; j -= gap) {
            nums[j + gap] = nums[j];
        }
        nums[j + gap] = tmp;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // gap作为间隔，每次遍历都除以2，缩小间隔，直到变为1，此时排序完成
        for(int gap = n / 2; gap >= 1; gap /= 2) {
            for(int i = gap; i<n; i++) {
                shellSort(nums, gap, i);
            }
        }
        return nums;
    }
};

class Solution {
    vector<int> tmp;
    void mergeSort(vector<int> &nums, int l, int r) {

        // 递归终止条件(只有一个元素时)
        if(l >= r) return;

        // 找到中间元素(用该种形式求的mid不会导致溢出)
        int mid = l + (r - l) / 2;

        // 自底向上
        // 用递归到最深层的只有两个元素时进行比较，然后再逐层向上合并
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        // 分为两个数组，分别以mid + 1 and l为起点
        // pos作为临时数组存放的指针，起点为l(因为俩子数组合并时的范围为l到r)
        int i = l, j = mid + 1, pos = l;
        while(i <= mid && j <= r) {
            // 将小的元素放入tmp数组中
            if(nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        // 比较后有剩余元素，则将它合并到tmp数组中
        for(int k = i; k<=mid; k++) {
            tmp[pos++] = nums[k];
        }
        for(int k = j; k<=r; k++) {
            tmp[pos++] = nums[k];
        }
        // 最后将tmp数组拷贝到nums数组中(注意拷贝起点和存放起点)
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        tmp = nums;
        mergeSort(nums, 0, n-1);
        return nums;
    }
};

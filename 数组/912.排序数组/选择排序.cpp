class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // selectSort
        // 选择在单调递增区间上不符合递增条件的元素
        int minIndex;
        for(int i=0; i<nums.size()-1; i++) {
            // 在区间0到i-1上数组已经正序，所以下一个for循环找到的值肯定小于nums[i]，才能和nums[i]交换，满足正序
            minIndex = i;
            for(int j = i+1; j<nums.size(); j++) {
                // 找到在区间i+1到n-1上最小的元素，下标记录到minIndex上
                if(nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            // 交换
            swap(nums[i], nums[minIndex]);
        }
        return nums;
    }
};

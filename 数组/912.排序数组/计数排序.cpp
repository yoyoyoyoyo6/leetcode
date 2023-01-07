class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int numsMax = nums[0], numsMin = nums[0];
        for(int i=1; i<n; i++) {
            if(numsMax < nums[i]) numsMax = nums[i];
            if(numsMin > nums[i]) numsMin = nums[i];
        }
        // numsMax - numsMin + 1 能计算出统计数组中的元素个数
        // 在算法导论中对统计数组大小的定义为k(k为nums数组中元素的上界，nums数组中的元素都在区间[0..k]内)
        // 无重复元素的严格递增的[0...k],用numsMax - numsMin + 1就能算出k
        // 最大值减去最小值小于或等于num的子数组数量/子数组的取值范围
        vector<int> counts(numsMax - numsMin + 1, 0);
        for(int i = 0; i<n; i++) {
            // key中减去numsMin的目的是让counts数组中下标的下界始终为0
            // 让下标从0开始(numsMin - numsMin为0)
            // 记录每个元素出现的次数
            ++counts[nums[i] - numsMin];
        }
        int index = 0;
        for(int i=0; i<counts.size(); i++) {
            while(counts[i] != 0) {
                // counts[i]不为0，则说明当前元素在nums中出现过
                // 当前的i对应着counts的下标 == nums[i] - numsMin
                // 所以加上numsMin则能得到当前正确位置的nums[i]
                nums[index++] = i + numsMin;
                // 让出现次数-1
                counts[i]--;
            }
        }
        return nums;
    }
};

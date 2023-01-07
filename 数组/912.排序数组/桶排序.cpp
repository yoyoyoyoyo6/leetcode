class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // bucketsort 
        // 分治算法的体现，将nums数组划分为几个部分(划分)（放到相应的桶中），
        //      对桶内的元素进行排序（解决），最后合并桶(合并)

        int n = nums.size();

        // 找到nums数组中的最大最小值
        // 用于计算buckets每个桶的大小
        int numsMax = nums[0], numsMin = nums[0];
        for(int i=1; i<n; i++) {
            if(numsMax < nums[i]) numsMax = nums[i];
            if(numsMin > nums[i]) numsMin = nums[i];
        }

        // 初始化桶
        int bucketNum = 5, bucketSize = (numsMax - numsMin) / bucketNum + 1;
        vector<vector<int>> buckets(bucketNum, vector<int>(0));

        // 将nums数组中的元素分到相应的桶中
        for(int num : nums) {
            int bucketIndex = (num - numsMin) / bucketSize;
            buckets[bucketIndex].emplace_back(num);
        }

        // 桶内排序
        for(int i = 0; i<buckets.size(); i++) {
            sort(buckets[i].begin(), buckets[i].end());
        }

        // 合并桶
        int numsIndex = 0;
        for(auto &bucket : buckets) {
            for(int num : bucket) {
                nums[numsIndex++] = num;
            }
        }

        return nums;
    }
};
